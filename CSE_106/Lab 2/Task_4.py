import pandas as pd
import matplotlib.pyplot as plt

# read the file into a pandas dataframe
df = pd.read_csv("weather_data.txt")

# a. Actual max temperature and actual min temperature on the same line chart
plt.plot(df["date"], df["actual_max_temp"], 'r', label='Actual Max Temp')
plt.plot(df["date"], df["actual_min_temp"], 'b', label='Actual Min Temp')
plt.title("4A: Actual Max and Min Temperature")
plt.xlabel("Date")
plt.ylabel("Temperature (°F)")
plt.legend(loc='best')
plt.show()

# b. A histogram of actual precipitation
plt.hist(df["actual_precipitation"], bins=10, color='blue', alpha=0.5)
plt.title("4B: Actual Precipitation")
plt.xlabel("Precipitation (inches)")
plt.ylabel("Frequency")
plt.show()
