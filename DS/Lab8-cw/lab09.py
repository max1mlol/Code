import math
import random

import matplotlib.pyplot as pylab

# =====================================================
# Даалгавар 1: Зоос шидэх симуляц
# =====================================================


def sim_coin_flips(num_flips):
    """num_flips удаа зоос шидэж, 'Heads' буух хувийг буцаана."""
    flips = [random.choice(['H', 'T']) for _ in range(num_flips)]
    return flips.count('H') / num_flips


for n in [10, 100, 1000, 10000]:
    result = sim_coin_flips(n)
    print(f"Flips: {n:6d} | Heads probability: {result:.4f}")

# =====================================================
# Даалгавар 2: Санамсаргүй алхалт
# =====================================================


class SimpleLocation:
    """2 хэмжээст байршлыг илэрхийлэх класс."""

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def move(self, dx, dy):
        """Шинэ байршлын SimpleLocation объект буцаана."""
        return SimpleLocation(self.x + dx, self.y + dy)
    def get_dist(self, other):
        """Евклидийн зайг буцаана."""
        return math.sqrt((self.x - other.x) ** 2 + (self.y - other.y) ** 2)

def one_dimension_walk(num_steps):
    """1 хэмжээст санамсаргүй алхалт явуулж эцсийн байршлыг буцаана."""
    current = SimpleLocation(0, 0)
    for _ in range(num_steps):
        step = random.choice([1, -1])
        current = current.move(step, 0)
    return current.x


# =====================================================
# Даалгавар 3: Статистик дүн шинжилгээ
# =====================================================

NUM_TRIALS = 50
NUM_STEPS = 100

end_positions = [one_dimension_walk(NUM_STEPS) for _ in range(NUM_TRIALS)]
origin = SimpleLocation(0,0)
distances = [origin.get_dist(SimpleLocation(pos, 0)) for pos in end_positions]

avg_dist = sum(distances) / len(distances)
max_dist = max(distances)
min_dist = min(distances)

print(f"\n---  Statistic dun shinjilgee ({NUM_TRIALS} turshilt, {NUM_STEPS} alham ---)")
print(f"Dundaj zai: {avg_dist:.4f}")
print(f"Hamgiin ih zai: {max_dist:.4f}")
print(f"Hamgiin baga zai: {min_dist:.4f}")

# =====================================================
# Даалгавар 4: Графикаар дүрслэх
# =====================================================

trial_numbers = list(range(1, NUM_TRIALS + 1))
pylab.figure(figsize=(10, 6))
pylab.scatter(trial_numbers, end_positions, color='black', alpha=0.7, edgecolors='black', s=60, label='Etsiin bairshil')
pylab.axhline(0, color='red', linestyle='--', linewidth=1.5, label=f'Lavlah shugam (0.00)')
pylab.axhline(avg_dist, color='blue', linestyle='--', linewidth=1.5, label=f'Dundaj zai ({avg_dist:.2f})')
pylab.title(f'1D sanamsargui alhalt - {NUM_TRIALS} turshilt, {NUM_STEPS} alham', fontsize=12)
pylab.xlabel('Turshiltiin dugaar', fontsize=12)
pylab.ylabel('Etsiin bairshil', fontsize=12)
pylab.legend()
pylab.grid(True, linestyle='--', alpha=0.5)
pylab.tight_layout()
pylab.savefig('lab09_random_walk.png', dpi=150)
pylab.show()
print("\nGraphic hadgalagdlaa: lab09_random_walk.png")

