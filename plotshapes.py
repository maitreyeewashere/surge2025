import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from io import StringIO

data = """
nproc,shape,runtime,avghops
32,2x4x4,44.05,2.09
32,2x2x8,46.05,3.25
32,4x2x4,44.05,2.06
64,4x4x4,53.32,2.34
64,2x8x4,55.32,3.3
64,8x4x2,55.32,3.3
128,4x4x8,64.6,3.42
128,2x8x8,66.6,4.25
128,4x8x4,64.6,3.39
256,4x8x8,75.87,4.23
256,2x16x8,82.72,6.71
256,16x4x4,80.67,5.73
"""

df = pd.read_csv(StringIO(data))

sns.set(style="whitegrid", palette="Set3")
sns.set_context("poster")

plt.figure(figsize=(14, 6))
bar_plot = sns.barplot(data=df, x="shape", y="runtime", hue="nproc")
plt.title("Runtime for Torus Shape vs Number of Processes", fontsize=26)
plt.xlabel("Torus Shape", fontsize=30)
plt.ylabel("Runtime (μs)", fontsize=30)
plt.xticks(rotation=45, fontsize=24)
plt.yticks(fontsize=18)
plt.legend(title="nproc", title_fontsize=28, fontsize=24)

plt.tight_layout()
plt.show()
