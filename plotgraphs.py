import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# Read the data
data = pd.read_csv("outputs2.csv")

# Set style and context
sns.set(style="whitegrid", palette="Set2")
sns.set_context("poster")

# Create 3 vertically stacked subplots
fig, axes = plt.subplots(3, 1, figsize=(14, 18), sharex=True, constrained_layout=True)


font_title = 24
font_label = 20
font_tick = 16
font_legend = 18

line_width = 2.5
marker_size = 10

# Plot 1: Runtime
sns.lineplot(ax=axes[0], data=data, x="n_proc", y="runtime", hue="operation",
             marker="o", linewidth=line_width, markersize=marker_size)
axes[0].set_title("Runtime vs Number of Processes", fontsize=font_title)
axes[0].set_ylabel("Runtime (μs)", fontsize=font_label)
axes[0].set_xlabel("")
axes[0].tick_params(axis='both', labelsize=font_tick)
axes[0].legend(fontsize=font_legend, title="Operation", title_fontsize=font_label)

# Plot 2: Average Hops
sns.lineplot(ax=axes[1], data=data, x="n_proc", y="avg_hops", hue="operation",
             marker="o", linewidth=line_width, markersize=marker_size, legend=False)
axes[1].set_title("Average Hops vs Number of Processes", fontsize=font_title)
axes[1].set_ylabel("Average Hops", fontsize=font_label)
axes[1].set_xlabel("")
axes[1].tick_params(axis='both', labelsize=font_tick)

# Plot 3: Total Hops
sns.lineplot(ax=axes[2], data=data, x="n_proc", y="total_hops", hue="operation",
             marker="o", linewidth=line_width, markersize=marker_size, legend=False)
axes[2].set_title("Total Hops vs Number of Processes", fontsize=font_title)
axes[2].set_ylabel("Total Hops", fontsize=font_label)
axes[2].set_xlabel("Number of Processes", fontsize=font_label)
axes[2].tick_params(axis='both', labelsize=font_tick)

# Adjust layout spacing
#plt.tight_layout(h_pad=3.5)
plt.subplots_adjust(bottom=0.05, top=0.95)

plt.show()
