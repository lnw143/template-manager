import json

def parse(name: str, prefix: str, source: str) -> dict:
	return {
		f'{name}': {
			'prefix': f'{prefix}',
			'body': source.split('\n'),
		}
	}

def dict_merge(a: dict, b: dict) -> dict:
	return {**a, **b}

def dict_to_json(x: dict) -> str:
	return json.dumps(x, indent=4)
