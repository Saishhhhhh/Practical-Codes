import os
import json
import re

readme_content = "# ANN Practical Codes\n\n"

exp_count = 1
for filename in sorted(os.listdir('.')):
    if filename.endswith('.ipynb'):
        with open(filename, 'r', encoding='utf-8') as f:
            try:
                data = json.load(f)
                first_cell = data['cells'][0]
                source = first_cell.get('source', [])
                content = "".join(source)
                
                # Parse Title and Problem Statement
                title_match = re.search(r'Title\s*:\s*(.*?)(?:\n|$)', content, re.IGNORECASE)
                ps_match = re.search(r'Problem Statement\s*:\s*(.*?)(?:\n|$)', content, re.IGNORECASE)
                
                title = title_match.group(1).strip() if title_match else "No Title Found"
                ps = ps_match.group(1).strip() if ps_match else "No Problem Statement Found"
                
                readme_content += f"**Exp {exp_count}**\n\n"
                readme_content += f"**Title:** [{title}]({filename})\n\n"
                readme_content += f"**Problem Statement:** {ps}\n\n<br>\n\n"
                
                exp_count += 1
            except Exception as e:
                print(f"Error reading {filename}: {e}")

with open('README.md', 'w', encoding='utf-8') as f:
    f.write(readme_content)
    
print("README.md generated successfully.")
