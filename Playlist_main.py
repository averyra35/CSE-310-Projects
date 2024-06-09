from Firebase import db

def create_playlist():
    playlistName = input("Enter playlsit name: ")
    songs = []
    print("Enter the songs and their artist (type 'done' when finished)")
    while True:
        song_name = input("Enter Song name: ")
        if song_name.lower() == 'done':
            break
        artist = input("Enter artist's name: ")
        song = {"Song Name": song_name, "Artist": artist}
        songs.append(song)
    if not playlistName or not songs:
        print("Name of playlist and songs are required")
        return
    
    playlist_ref = db.collection('Playlists').document(playlistName)
    playlist_ref.set({
        'songs': songs
    })
    print(f"Playlist '{playlistName}' created")

def get_playlist():
    playlistName = input("Enter playlist name: ")
    playlist_ref = db.collection('Playlists').document(playlistName)
    playlist = playlist_ref.get()

    if not playlist.exists:
        print("Playlist not found")
        return
    
    playlist_songs = playlist.to_dict()
    print(f"\nPlaylist {playlistName}:")
    for song in playlist_songs.get('songs', []):
        print(f"    Song: {song}")

def add_song():
    playlistName = input("Enter playlist name: ")
    playlist_ref = db.collection('Playlists').document(playlistName)
    playlist = playlist_ref.get()
    
    if not playlist.exists:
        print("Playlist not found")
        return

    song_name = input("Enter song name: ")
    artist = input("Enter artist's name: ")
    new_song = {"Song Name": song_name, "Artist": artist}
    
    songs = playlist.to_dict().get('songs', [])
    songs.append(new_song)
    playlist_ref.update({'songs': songs})
    
    print(f"Song: '{song_name}' by {artist} added to playlist '{playlistName}'.")

def remove_song():
    playlistName = input("Enter the playlist name: ")
    playlist_ref = db.collection('Playlists').document(playlistName)
    playlist = playlist_ref.get()
    
    if not playlist.exists:
        print("Playlist not found")
        return

    song_name = input("Enter the song name to remove: ")
    songs = playlist.to_dict().get('songs', [])
    
    updated_songs = [song for song in songs if song['Song Name'] != song_name]
    if len(updated_songs) == len(songs):
        print(f"Song: '{song_name}' not found in playlist '{playlistName}'.")
        return
    
    playlist_ref.update({'songs': updated_songs})
    print(f"Song: '{song_name}' removed from playlist '{playlistName}'.")

def share_playlist():
    playlist_name = input("Enter the playlist name: ")
    print(f"Share this link to access the playlist: /get_playlist/{playlist_name}")

def main():

    while True:
        print("\nPlaylist Creator:\n1. Create new playlist\n2. Search for playlist\n3. Add a song to existing playlist\n4. Remove a song from existing playlist\n5. Share playlist\n0. Quit\n")
        choice = input(" ")
        if choice == '1':
            create_playlist()
        if choice == '2':
            get_playlist()
        if choice == '3':
            add_song()
        if choice == '4':
            remove_song()
        if choice == '5':
            share_playlist()
        elif choice == '0':
            break

if __name__ == "__main__":
    main()