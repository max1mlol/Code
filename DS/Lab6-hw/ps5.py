# -*- coding: utf-8 -*-
# Problem Set 5: Experimental Analysis
# Name:
# Collaborators (discussion):
# Time:

import re

import pylab

# cities in our weather data
CITIES = [
    "BOSTON",
    "SEATTLE",
    "SAN DIEGO",
    "PHILADELPHIA",
    "PHOENIX",
    "LAS VEGAS",
    "CHARLOTTE",
    "DALLAS",
    "BALTIMORE",
    "SAN JUAN",
    "LOS ANGELES",
    "MIAMI",
    "NEW ORLEANS",
    "ALBUQUERQUE",
    "PORTLAND",
    "SAN FRANCISCO",
    "TAMPA",
    "NEW YORK",
    "DETROIT",
    "ST LOUIS",
    "CHICAGO",
]

TRAINING_INTERVAL = range(1961, 2010)
TESTING_INTERVAL = range(2010, 2016)

"""
Begin helper code
"""


class Climate(object):
    """
    The collection of temperature records loaded from given csv file
    """

    def __init__(self, filename):
        """
        Initialize a Climate instance, which stores the temperature records
        loaded from a given csv file specified by filename.

        Args:
            filename: name of the csv file (str)
        """
        self.rawdata = {}
        f = open(filename, "r")
        header = f.readline().strip().split(",")
        for line in f:
            items = line.strip().split(",")
            date = re.match("(\d\d\d\d)(\d\d)(\d\d)", items[header.index("DATE")])
            year = int(date.group(1))
            month = int(date.group(2))
            day = int(date.group(3))
            city = items[header.index("CITY")]
            temperature = float(items[header.index("TEMP")])
            if city not in self.rawdata:
                self.rawdata[city] = {}
            if year not in self.rawdata[city]:
                self.rawdata[city][year] = {}
            if month not in self.rawdata[city][year]:
                self.rawdata[city][year][month] = {}
            self.rawdata[city][year][month][day] = temperature
        f.close()

    def get_yearly_temp(self, city, year):
        """
        Get the daily temperatures for the given year and city.

        Args:
            city: city name (str)
            year: the year to get the data for (int)

        Returns:
            a 1-d pylab array of daily temperatures for the specified year and
            city
        """
        temperatures = []
        assert city in self.rawdata, "provided city is not available"
        assert year in self.rawdata[city], "provided year is not available"
        for month in range(1, 13):
            for day in range(1, 32):
                if day in self.rawdata[city][year][month]:
                    temperatures.append(self.rawdata[city][year][month][day])
        return pylab.array(temperatures)

    def get_daily_temp(self, city, month, day, year):
        """
        Get the daily temperature for the given city, month, day, and year.

        Args:
            city: city name (str)
            month: the month to get the data for (int)
            day: the day to get the data for (int)
            year: the year to get the data for (int)

        Returns:
            a float for the daily temperature
        """
        assert city in self.rawdata, "provided city is not available"
        assert year in self.rawdata[city], "provided year is not available"
        assert month in self.rawdata[city][year], "provided month is not available"
        assert day in self.rawdata[city][year][month], "provided day is not available"
        return self.rawdata[city][year][month][day]


def se_over_slope(x, y, estimated, model):
    assert len(y) == len(estimated)
    assert len(x) == len(estimated)
    EE = ((estimated - y) ** 2).sum()
    var_x = ((x - x.mean()) ** 2).sum()
    SE = pylab.sqrt(EE / (len(x) - 2) / var_x)
    return SE / model[0]


"""
End helper code
"""


def generate_models(x, y, degs):
    """
    Generate regression models by fitting a polynomial for each degree in degs
    to points (x, y).

    Args:
        x: an 1-d pylab array with length N, representing the x-coordinates of
            the N sample points
        y: an 1-d pylab array with length N, representing the y-coordinates of
            the N sample points
        degs: a list of degrees of the fitting polynomial

    Returns:
        a list of pylab arrays, where each array is a 1-d array of coefficients
        that minimizes the squared error of the fitting polynomial
    """
    return [pylab.polyfit(x, y, deg) for deg in degs]


def r_squared(y, estimated):
    """
    Calculate the R-squared error term.

    Args:
        y: 1-d pylab array with length N, representing the y-coordinates of the
            N sample points
        estimated: an 1-d pylab array of values estimated by the regression
            model

    Returns:
        a float for the R-squared error term
    """
    mean = y.mean()
    ss_res = ((y - estimated) ** 2).sum()
    ss_tot = ((y - mean) ** 2).sum()
    return float(1 - ss_res / ss_tot)


def evaluate_models_on_training(x, y, models):
    """
    For each regression model, compute the R-squared value for this model with the
    standard error over slope of a linear regression line (only if the model is
    linear), and plot the data along with the best fit curve.

    For the plots, you should plot data points (x,y) as blue dots and your best
    fit curve (aka model) as a red solid line. You should also label the axes
    of this figure appropriately and have a title reporting the following
    information:
        degree of your regression model,
        R-square of your model evaluated on the given data points,
        and SE/slope (if degree of this model is 1 -- see se_over_slope).

    Args:
        x: an 1-d pylab array with length N, representing the x-coordinates of
            the N sample points
        y: an 1-d pylab array with length N, representing the y-coordinates of
            the N sample points
        models: a list containing the regression models you want to apply to
            your data. Each model is a pylab array storing the coefficients of
            a polynomial.

    Returns:
        None
    """
    for model in models:
        deg = len(model) - 1
        estimated = pylab.polyval(model, x)
        r2 = r_squared(y, estimated)

        pylab.figure()
        pylab.plot(x, y, 'bo', label='Data points')
        pylab.plot(x, estimated, 'r-', label='Regression curve')
        pylab.xlabel('Year')
        pylab.ylabel('Temperature (Celsius)')

        if deg == 1:
            se = se_over_slope(x, y, estimated, model)
            pylab.title(
                'Degree: %d | R\u00b2: %.4f | SE/slope: %.4f' % (deg, r2, se)
            )
        else:
            pylab.title('Degree: %d | R\u00b2: %.4f' % (deg, r2))

        pylab.legend()


def gen_cities_avg(climate, multi_cities, years):
    """
    Compute the average annual temperature over multiple cities.

    Args:
        climate: instance of Climate
        multi_cities: the names of cities we want to average over (list of str)
        years: the range of years of the yearly averaged temperature (list of
            int)

    Returns:
        a pylab 1-d array of floats with length = len(years). Each element in
        this array corresponds to the average annual temperature over the given
        cities for a given year.
    """
    result = []
    for year in years:
        city_annual_avgs = [
            climate.get_yearly_temp(city, year).mean()
            for city in multi_cities
        ]
        result.append(pylab.array(city_annual_avgs).mean())
    return pylab.array(result)


def moving_average(y, window_length):
    """
    Compute the moving average of y with specified window length.

    Args:
        y: an 1-d pylab array with length N, representing the y-coordinates of
            the N sample points
        window_length: an integer indicating the window length for computing
            moving average

    Returns:
        an 1-d pylab array with the same length as y storing moving average of
        y-coordinates of the N sample points
    """
    result = []
    for i in range(len(y)):
        start = max(0, i - window_length + 1)
        window = y[start:i + 1]
        result.append(sum(window) / len(window))
    return pylab.array(result)


def rmse(y, estimated):
    """
    Calculate the root mean square error term.

    Args:
        y: an 1-d pylab array with length N, representing the y-coordinates of
            the N sample points
        estimated: an 1-d pylab array of values estimated by the regression
            model

    Returns:
        a float for the root mean square error term
    """
    return float(pylab.sqrt(((y - estimated) ** 2).mean()))


def gen_std_devs(climate, multi_cities, years):
    """
    For each year in years, compute the standard deviation over the averaged yearly
    temperatures for each city in multi_cities.

    Args:
        climate: instance of Climate
        multi_cities: the names of cities we want to use in our std dev calculation (list of str)
        years: the range of years to calculate standard deviation for (list of int)

    Returns:
        a pylab 1-d array of floats with length = len(years). Each element in
        this array corresponds to the standard deviation of the average annual
        city temperatures for the given cities in a given year.
    """
    result = []
    for year in years:
        city_temps = pylab.array([
            climate.get_yearly_temp(city, year)
            for city in multi_cities
        ])
        # Average across cities for each day
        daily_avg = city_temps.mean(axis=0)
        result.append(daily_avg.std())
    return pylab.array(result)


def evaluate_models_on_testing(x, y, models):
    """
    For each regression model, compute the RMSE for this model and plot the
    test data along with the model's estimation.

    For the plots, you should plot data points (x,y) as blue dots and your best
    fit curve (aka model) as a red solid line. You should also label the axes
    of this figure appropriately and have a title reporting the following
    information:
        degree of your regression model,
        RMSE of your model evaluated on the given data points.

    Args:
        x: an 1-d pylab array with length N, representing the x-coordinates of
            the N sample points
        y: an 1-d pylab array with length N, representing the y-coordinates of
            the N sample points
        models: a list containing the regression models you want to apply to
            your data. Each model is a pylab array storing the coefficients of
            a polynomial.

    Returns:
        None
    """
    for model in models:
        deg = len(model) - 1
        estimated = pylab.polyval(model, x)
        error = rmse(y, estimated)

        pylab.figure()
        pylab.plot(x, y, 'bo', label='Data points')
        pylab.plot(x, estimated, 'r-', label='Regression curve')
        pylab.xlabel('Year')
        pylab.ylabel('Temperature (Celsius)')
        pylab.title('Degree: %d | RMSE: %.4f' % (deg, error))
        pylab.legend()


if __name__ == "__main__":
    import matplotlib
    matplotlib.use('Agg')

    climate = Climate("data.csv")
    training_years = pylab.array(list(TRAINING_INTERVAL))
    testing_years = pylab.array(list(TESTING_INTERVAL))

    # Part A.4
    # A.4.I: January 10th temperature in New York (training)
    jan10_ny = pylab.array([
        climate.get_daily_temp("NEW YORK", 1, 10, year)
        for year in TRAINING_INTERVAL
    ])
    models_a4i = generate_models(training_years, jan10_ny, [1])
    evaluate_models_on_training(training_years, jan10_ny, models_a4i)
    pylab.savefig("partA4I.png", bbox_inches='tight')
    pylab.close()

    # A.4.II: Annual average temperature in New York (training)
    ny_annual_avg = pylab.array([
        climate.get_yearly_temp("NEW YORK", year).mean()
        for year in TRAINING_INTERVAL
    ])
    models_a4ii = generate_models(training_years, ny_annual_avg, [1])
    evaluate_models_on_training(training_years, ny_annual_avg, models_a4ii)
    pylab.savefig("partA4II.png", bbox_inches='tight')
    pylab.close()

    # Part B: National average across all cities (training)
    national_avg = gen_cities_avg(climate, CITIES, TRAINING_INTERVAL)
    models_b = generate_models(training_years, national_avg, [1])
    evaluate_models_on_training(training_years, national_avg, models_b)
    pylab.savefig("partB.png", bbox_inches='tight')
    pylab.close()

    # Part C: 5-year moving average of national temperature (training)
    national_avg_ma = moving_average(national_avg, 5)
    models_c = generate_models(training_years, national_avg_ma, [1])
    evaluate_models_on_training(training_years, national_avg_ma, models_c)
    pylab.savefig("partC.png", bbox_inches='tight')
    pylab.close()

    # Part D.2.1: Fit degree 1, 2, 20 to training moving average
    models_d = generate_models(training_years, national_avg_ma, [1, 2, 20])
    evaluate_models_on_training(training_years, national_avg_ma, models_d)
    for deg in [1, 2, 20]:
        pylab.savefig("partD21_deg%d.png" % deg, bbox_inches='tight')
        pylab.close()

    # Part D.2.2: Predict 2010-2015 and evaluate
    national_avg_test = gen_cities_avg(climate, CITIES, TESTING_INTERVAL)
    national_avg_test_ma = moving_average(national_avg_test, 5)
    evaluate_models_on_testing(testing_years, national_avg_test_ma, models_d)
    for deg in [1, 2, 20]:
        pylab.savefig("partD22_deg%d.png" % deg, bbox_inches='tight')
        pylab.close()

    # Part E: Standard deviations of daily temperatures across cities
    std_devs = gen_std_devs(climate, CITIES, TRAINING_INTERVAL)
    std_devs_ma = moving_average(std_devs, 5)
    models_e = generate_models(training_years, std_devs_ma, [1])
    evaluate_models_on_training(training_years, std_devs_ma, models_e)
    pylab.savefig("partE.png", bbox_inches='tight')
    pylab.close()

    print("All plots saved successfully.")