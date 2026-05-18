import random
import string
import tkinter as tk
from tkinter import messagebox

def build_pool(use_upper, use_lower, use_digits, use_symbols):

    pool = ""

    if use_upper:
        pool = pool + string.ascii_uppercase
    if use_lower:
        pool = pool + string.ascii_lowercase
    if use_digits:
        pool = pool + string.digits
    if use_symbols:
        pool = pool + string.punctuation

    return pool

def generate_password(length, use_upper, use_lower, use_digits, use_symbols):

    if not (use_upper or use_lower or use_digits or use_symbols):
        return "ERROR: pick at least one character type"

    if length < 1:
        return "ERROR: length must be at least 1"

    pool = build_pool(use_upper, use_lower, use_digits, use_symbols)

    chars = []

    if use_upper:
        chars.append(random.choice(string.ascii_uppercase))
    if use_lower:
        chars.append(random.choice(string.ascii_lowercase))
    if use_digits:
        chars.append(random.choice(string.digits))
    if use_symbols:
        chars.append(random.choice(string.punctuation))

    for i in range(length - len(chars)):
        chars.append(random.choice(pool))

    chars = chars[:length]

    random.shuffle(chars)

    return "".join(chars)

def get_strength(length, use_upper, use_lower, use_digits, use_symbols):

    types_chosen = sum([use_upper, use_lower, use_digits, use_symbols])

    if length < 8 or types_chosen <= 1:
        return "Weak"
    elif length < 12 or types_chosen == 2:
        return "Fair"
    elif length < 16 or types_chosen == 3:
        return "Strong"
    else:
        return "Very Strong"

BG      = "#f0f4f8"
BTN     = "#4a90d9"
BTN_TXT = "white"
TITLE   = "#2c3e50"

class App:

    def __init__(self, window):
        self.window = window
        self.window.title("Password Generator")
        self.window.configure(bg=BG)

        tk.Label(
            window,
            text="Password Generator",
            font=("Arial", 16, "bold"),
            bg=BG,
            fg=TITLE
        ).grid(row=0, column=0, columnspan=2, pady=(15, 5))

        tk.Label(
            window,
            text="Choose your options and click Generate",
            font=("Arial", 9),
            bg=BG,
            fg="grey"
        ).grid(row=1, column=0, columnspan=2, pady=(0, 10))

        tk.Label(window, text="Password length:", bg=BG, font=("Arial", 10)).grid(row=2, column=0, sticky="w", padx=15, pady=5)
        self.length_var = tk.IntVar(value=16)
        tk.Spinbox(window, from_=4, to=64, textvariable=self.length_var, width=5, font=("Arial", 10)).grid(row=2, column=1, sticky="w")

        self.use_upper   = tk.BooleanVar(value=True)
        self.use_lower   = tk.BooleanVar(value=True)
        self.use_digits  = tk.BooleanVar(value=True)
        self.use_symbols = tk.BooleanVar(value=False)

        tk.Checkbutton(window, text="Uppercase (A-Z)",  variable=self.use_upper,   bg=BG, font=("Arial", 10)).grid(row=3, column=0, columnspan=2, sticky="w", padx=15)
        tk.Checkbutton(window, text="Lowercase (a-z)",  variable=self.use_lower,   bg=BG, font=("Arial", 10)).grid(row=4, column=0, columnspan=2, sticky="w", padx=15)
        tk.Checkbutton(window, text="Numbers  (0-9)",   variable=self.use_digits,  bg=BG, font=("Arial", 10)).grid(row=5, column=0, columnspan=2, sticky="w", padx=15)
        tk.Checkbutton(window, text="Symbols  (!@#...)",variable=self.use_symbols, bg=BG, font=("Arial", 10)).grid(row=6, column=0, columnspan=2, sticky="w", padx=15)

        tk.Button(
            window,
            text="Generate Password",
            command=self.on_generate,
            bg=BTN, fg=BTN_TXT,
            font=("Arial", 10, "bold"),
            relief="flat",
            padx=10, pady=5
        ).grid(row=7, column=0, columnspan=2, pady=15)

        tk.Label(window, text="Your password:", bg=BG, font=("Arial", 10)).grid(row=8, column=0, sticky="w", padx=15)
        self.result_var = tk.StringVar(value="")
        tk.Entry(
            window,
            textvariable=self.result_var,
            width=30,
            state="readonly",
            font=("Courier", 11),
            relief="solid",
            bd=1
        ).grid(row=9, column=0, columnspan=2, padx=15, pady=5)

        tk.Button(
            window,
            text="Copy to clipboard",
            command=self.copy,
            bg=BTN, fg=BTN_TXT,
            font=("Arial", 9),
            relief="flat",
            padx=8, pady=3
        ).grid(row=10, column=0, columnspan=2, pady=5)

        self.strength_label = tk.Label(window, text="Strength: -", bg=BG, font=("Arial", 10))
        self.strength_label.grid(row=11, column=0, columnspan=2, pady=(5, 15))

    def on_generate(self):

        try:
            length = int(self.length_var.get())
        except ValueError:
            messagebox.showerror("Error", "Length must be a number.")
            return

        password = generate_password(
            length,
            self.use_upper.get(),
            self.use_lower.get(),
            self.use_digits.get(),
            self.use_symbols.get()
        )

        if password.startswith("ERROR:"):
            messagebox.showwarning("Oops", password)
            return

        self.result_var.set(password)

        strength = get_strength(
            length,
            self.use_upper.get(),
            self.use_lower.get(),
            self.use_digits.get(),
            self.use_symbols.get()
        )

        colors = {"Weak": "red", "Fair": "orange", "Strong": "green", "Very Strong": "green"}
        self.strength_label.config(text="Strength: " + strength, fg=colors[strength])

    def copy(self):

        pw = self.result_var.get()
        if pw == "":
            messagebox.showinfo("Nothing to copy", "Generate a password first.")
            return
        self.window.clipboard_clear()
        self.window.clipboard_append(pw)
        messagebox.showinfo("Copied!", "Password copied to clipboard.")

if __name__ == "__main__":
    window = tk.Tk()
    app = App(window)
    window.mainloop()
