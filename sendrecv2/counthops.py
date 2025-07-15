import re
import csv

print("MPI bcast on Torus")

filename = input("Enter filename: ")
with open(filename, "r") as file:
    lines = file.readlines()

# Pattern to extract src, dst, and hop count
hop_pattern = re.compile(r"\[HOP\] src\s*=\s*(\d+)\s*dst\s*=\s*(\d+)\s*=\s*(\d+)")

hop_data = []
for line in lines:
    match = hop_pattern.search(line)
    if match:
        src, dst, hops = map(int, match.groups())
        hop_data.append((src, dst, hops))
    if line.startswith("E"):
        print(line)

if not hop_data:
    print("No hop data found.")
else:
    total = sum(h[2] for h in hop_data)
    avg = total / len(hop_data)

    print(f"Total hops: {total}")
    print(f"Average hops per pair: {avg:.2f}")
