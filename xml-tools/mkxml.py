import re
import sys

# Get the input file and values file from command line arguments
if len(sys.argv) < 3:
    print("Usage: python replace_keys.py <input_file> <values_file>")
    sys.exit(1)
input_file = sys.argv[1]
values_file = sys.argv[2]

# Read in the files
with open(input_file, 'r') as f1, open(values_file, 'r') as f2:
    input_text = f1.read()
    values_text = f2.read()

# Create a dictionary of key-value pairs from the values file
values_dict = {}
for line in values_text.split('\n'):
    if line.strip() == '':
        continue
    key, value = line.split(None, 1)
    values_dict[key] = value.strip()

# Replace all occurrences of %<key>% with the corresponding value
output_text = re.sub(r'%(.+?)%', lambda m: values_dict.get(m.group(1), m.group(0)), input_text)

# Write the output to a file
with open(values_dict['ProductName']+'-template.xml', 'w') as f3:
    f3.write(output_text)

