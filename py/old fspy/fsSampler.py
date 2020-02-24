# fs sampler
# version: 0.1
# Dieses Programm dient dazu anhand von spezifischen Parametern aus der online Library Free Sound Dateien zu selektieren und diese in ein Verzeichnis lokal runter zu laden

from __future__ import print_function
import freesound
import os
import sys
from oauthlib.oauth2 import BackendApplicationClient
from requests_oauthlib import OAuth2Session
import hashlib
import random
import time
import subprocess

class config():
	"""
	Start here to edit your config of the program
	"""
	APIKEY="Ld15pPetuu7VMVOGEzgkrvTp23IaiplOUmuszK44"
	OAUTHTOKEN="VegqtgKdHqbR0KwcElFha5FvC2vhhQ"
	FETCHDIRNAME = "fetchedSounds"
	COUNT = 10 #Maximale Anzahl der Sounds (-1 für unbegrenzt)
	PAGESIZE = 300 #Ergebnisse pro Abruf von Freesounds INT (Seitenbasiert, Seite n kann spezifiziert werden)


class fsFetcher():
	def __init__(self):
		self.fsClient = freesound.FreesoundClient()
		self.fsClient.set_token(config.APIKEY)


		self.path_name = os.path.join(os.getcwd(), config.FETCHDIRNAME)
		try:
			os.mkdir(self.path_name)
			os.mkdir(self.path_name+'/wav')
		except:
			pass
	def md5(self,fname):
	    hash_md5 = hashlib.md5()
	    with open(fname, "rb") as f:
	        for chunk in iter(lambda: f.read(4096), b""):
	            hash_md5.update(chunk)
	    return hash_md5.hexdigest()	

	def selectSounds(self, minDuration=1, maxDuration=20, geo=[40,74,1000]):
		"""
		Diese Methode wählt Sounds aufgrund folgender Parameter aus der Freesound Library
		Parameter: minimale Dauer, maximale Dauer, Geotags: Breitengrad, Längengrad, Entfernung (Radius) als INT
				
		Text Search Request:
        >>> sounds = c.text_search(
        >>>     query="dubstep", filter="tag:loop", fields="id,name,url"
        >>> )
        >>> for snd in sounds: print snd.name

		Geotag Filter:
			#filter={!geofilt sfield=geotag pt=<LATITUDE>,<LONGITUDE> d=<MAX_DISTANCE_IN_KM>}
		"""
		
		soundGeoTagging = geo
		start = time.time()
		queryFilter = "{{!geofilt sfield=geotag pt={0},{1} d={2}}}".format(geo[0],geo[1],geo[2])
		#queryFilter = "type:wav {!geofilt sfield=geotag pt=13,52 d=2000}"
		queryFields ="id,name,duration,md5,type,previews"
		sounds = self.fsClient.text_search(filter=queryFilter,fields=queryFields, page_size=config.PAGESIZE)
		stop  = time.time()
		print ("dauer für freesounds abruf: ")
		print (stop-start)
		return self.filterByDuration(sounds, minDuration, maxDuration)

	def downloadSounds(self, soundsObject):
		#self.fsClient.set_token(config.OAUTHTOKEN, "oauth")
		"""
		Download Sound Files
		Erwartet ein Sound Objekt mit einer Liste von Sounds
		"""
		i = 0
		for sound in soundsObject:
			if (i >= 0) & (i < config.COUNT):
				self.nameFileByIndex(sound, i)
				#filename = "sound_"+str(i)+".wav"
				#sound.retrieve_preview(self.path_name, name=filename)
				i += 1
			else:
				return
		return
	def nameFileByIndex(self, soundObject, i):
		filename = "sound_"+str(i)
		print("\t\tDownloading:", soundObject.name)
		print("as: "+filename)
		soundObject.retrieve_preview(self.path_name, name=filename)
		subprocess.call(['ffmpeg', '-y', '-i', self.path_name+'/'+filename,self.path_name+'/wav/'+filename+'.wav'])
		return

	def nameFileByName(self, soundObject):
		fullfilepath = self.path_name+"/"+soundObject.name
		if (os.path.isfile(fullfilepath)):
			print ("dateiname vorhanden: "+soundObject.name)
		else:
			print ("datei muss geladen werden:")
			print("\t\tDownloading:", soundObject.name)
			#if sound.name.endswith(sound.type):
			filename = soundObject.name
			soundObject.retrieve_preview(self.path_name, name=filename)
			#else:
			#	filename = "%s.%s" % (sound.name, sound.type)
			#	sound.retrieve_preview(self.path_name, name=filename)
		return

	def filterByDuration(self, soundsObject, minDuration, maxDuration):
		sounds = soundsObject
		soundList = []
		tmp = time.time()
		for sound in sounds:
			soundList += [sound]
		random.shuffle(soundList)
		filteredObjects = []
		i = 0
		print ("dauer für shuffle: ")
		print (time.time()-tmp)
		print (soundList)
		for sound in soundList:
			if (i >= 0) & (i < config.COUNT):
				if (int(sound.duration) >= minDuration) & (int(sound.duration) <= maxDuration):
					filteredObjects += [sound]
					i += 1
		print (filteredObjects)
		return filteredObjects

# Programmaufruf
appStart = time.time()
soundFetcher = fsFetcher()
sounds = soundFetcher.selectSounds()
download = soundFetcher.downloadSounds(sounds)
appStop  = time.time()
print ("Programmdauer: ")
print  (appStop - appStart)
