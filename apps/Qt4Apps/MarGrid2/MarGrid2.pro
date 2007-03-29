include (../Qt4Apps.pri)

TEMPLATE = app
TARGET = MarGrid2
INCLUDEPATH += . ..
# CONFIG += qt warn_on resources
QT += xml 


RESOURCES += MarGrid2.qrc

# Input
HEADERS	+= Music/MusicTrack.h Music/MusicLink.h Music/MusicCollection.h 
HEADERS += Widgets/PlayBox.h Widgets/Playlist.h Widgets/Tracklist.h
HEADERS += Widgets/Grid.h Widgets/Keypad.h
HEADERS += Dialogs/PreferencesDialog.h Dialogs/iTunesPage.h
HEADERS += Interface/Display.h Interface/Classifier.h Interface/Extractor.h Interface/Playback.h
HEADERS += Interface/Parser.h Interface/Playback.h
# HEADERS += Midi/MidiListener.h Midi/RtMidi.h Midi/RtError.h
HEADERS += Colormaps/Colormap.h Colormaps/GreyScaleColormap.h Colormaps/SpectraColormap.h
#HEADERS += Marsyas/MarsyasECP.h Marsyas/MarSystemWrapper.h
HEADERS += Parsers/iTunesXmlHandler.h Parsers/iTunesXmlWriter.h
HEADERS += MainWindow.h

SOURCES += Music/MusicTrack.cpp Music/MusicLink.cpp Music/MusicCollection.cpp  
SOURCES += Interface/Parser.cpp
SOURCES += Widgets/PlayBox.cpp Widgets/Playlist.cpp Widgets/Tracklist.cpp
SOURCES += Widgets/Grid.cpp Widgets/Keypad.cpp
SOURCES += Dialogs/PreferencesDialog.cpp Dialogs/iTunesPage.cpp
#Classifier.cpp Extractor.cpp 
# SOURCES += Midi/MidiListener.cpp Midi/RtMidi.cpp
SOURCES += Colormaps/Colormap.cpp Colormaps/GreyScaleColormap.cpp Colormaps/SpectraColormap.cpp
#SOURCES += Marsyas/MarsyasECP.cpp Marsyas/MarSystemWrapper.cpp
SOURCES += Parsers/iTunesXmlHandler.cpp Parsers/iTunesXmlWriter.cpp 
SOURCES += MainWindow.cpp

CONFIG(qtestlib) {
	message(Running Unit Tests)
	#HEADERS += Tests/FirstTest.h #UnitTests.h
	SOURCES += Tests/FirstTest.cpp #UnitTests.cpp

} else {
	SOURCES += main.cpp 
}

