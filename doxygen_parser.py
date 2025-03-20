import re

def parse_doxygen_comment(comment):
	lines = []
	for line in comment.split('\n'):
		line = line.strip().lstrip('*').strip()
		if line.startswith('///'):
			line = line[3:].strip()
		lines.append(line)
	
	parsed = {}
	
	for line in lines:
		if line.startswith('@'):
			tag_match = re.match(r'@(\w+)(?:\s+(.*))?', line)

			if tag_match:
				parsed[tag_match.group(1)] = tag_match.group(2)

	return parsed

def parse(source: str) -> dict | None:
	
	pattern = r'/\*\*(.*?)\*/'
	matches = re.findall(pattern, source, re.DOTALL)

	return parse_doxygen_comment(matches[0]) if matches else None
