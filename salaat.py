import requests
from bs4 import BeautifulSoup
import discord
import os

def get_salat():
    url = "https://habous.gov.ma/horaire%20de%20priere/widgets/portrait/horaire-2.php?ville=82"
    get = requests.get(url)
    out = BeautifulSoup(get.content, "html.parser")
    output = out.find_all("td")
    for i in output:
        print (str(i).replace("<td>", "").replace("</td>" ,"").strip())


token = "MTAzMDg1MDQzOTEwMjYwMzI5NA.GLDLU4.yPHdsUgpq4CkLrffnJjt8ABAV-tVwMmjifKj_w"

intents = discord.Intents.default()
intents.message_content = True

client = discord.Client(intents=intents)

@client.event
async def on_ready():
    print(f'We have logged in as {client.user}')

@client.event
async def on_message(message):
    if message.author == client.user:
        return

    if message.content.startswith('$Salat'):
        await message.channel.send('Hello!')

client.run(token)