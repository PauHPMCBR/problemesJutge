import requests

url = 'https://lolalytics.com/lol/twitch/build/'
r = requests.get(url)
print(r.text)