import re
import os, sys

import doxygen_parser, to_snippet

def search_files(directory, extension):
	files = []
	for file in os.listdir(directory):
		path = os.path.join(directory, file)
		if os.path.isfile(path) and file.endswith(extension):
			files.append(path)
		elif os.path.isdir(path):
			files.extend(search_files(path, extension))
	return files

directory = sys.argv[1] if len(sys.argv) > 1 else 'template'

snippet = {}

for file in search_files(directory, '.cpp'):
	with open(file, 'r') as f:
		source = f.read()
	
	parsed = doxygen_parser.parse(source)
	
	if not parsed or not parsed.get('name') or not parsed.get('prefix'):
		raise ValueError(f'Cannot determine the name or prefix of "{file}".')

	snippet = to_snippet.dict_merge(snippet, to_snippet.parse(parsed['name'], parsed['prefix'], source))

result = to_snippet.dict_to_json(snippet)

with open('cpp.json', 'w') as f:
    f.write(result)
