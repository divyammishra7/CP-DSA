print(df['Opened'].value_counts())


# Convert the 'Opened' column to datetime format with 'coerce' error handling
df['Opened'] = pd.to_datetime(df['Opened'], format='%m/%d/%y %I:%M %p', errors='coerce')

# Group the DataFrame by 'Server'
grouped_df = df.groupby('Server')

# Calculate the difference in Opened time between the first and last order for each group using diff() and dt.total_seconds() methods, and convert it to hours
time_diff = (grouped_df['Opened'].max() - grouped_df['Opened'].min()).dt.total_seconds() / 3600
hours_worked = time_diff.rename('Hours Worked')

# Add the 'Hours Worked' column to the original DataFrame
df = df.merge(hours_worked.to_frame(), on='Server', how='left')

# Calculate the total earnings per day for each group by adding tips, gratuity, and hourly wage
df['Total Earnings'] = df['Tip'] + df['Gratuity'] + (df['Hours Worked'] * 3)

fig, axes = plt.subplots(nrows=len(grouped_df), ncols=1, figsize=(10, 6 * len(grouped_df)))

# Create line graphs for each server's total earnings
for i, (server, data) in enumerate(grouped_df):
    ax = axes[i]  # Get the appropriate subplot
    ax.plot(data['Opened'], data['Total Earnings'], marker='o', linestyle='-', label=f"Server {server}")
    ax.set_title(f"Total Earnings Over Time for Server {server}")
    ax.set_xlabel('Time (Opened)')
    ax.set_ylabel('Total Earnings')
    ax.grid(True)
    ax.legend()

# Adjust layout and display the plot
plt.tight_layout()
plt.show()
# The dataset has 'Opened' column which might contain the time when the server started working on an order and based on that, I can calculate the working hours for each server. Also, there are 'Amount', 'Tip' and 'Gratuity' columns which can be used to calculate the total money made by each server. Additionally, I need to consider an hourly wage of $3 while calculating the total earnings