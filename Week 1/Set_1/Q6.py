# Printing calendar of August 2014

# Initialize a 6x7 matrix to represent the calendar (6 weeks, 7 days each)
calendar = [[0 for _ in range(7)] for _ in range(6)]

# August 2014 starts on a Friday
start_day = 5  # 0 for Sunday, so Friday is 5

day = 1  # Start from the 1st of August

# Fill the calendar with the days of August 2014
for index in range(start_day, start_day + 31):
    week = index // 7
    day_of_week = index % 7
    calendar[week][day_of_week] = day
    day += 1

# Weekday labels
weekdays = ["Sun","Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]

# Print the calendar
print("Calendar of August 2014:")
print("\t".join(weekdays))

for row in calendar:
    print("\t".join(str(col) if col != 0 else " " for col in row))
