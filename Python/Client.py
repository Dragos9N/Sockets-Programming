import socket

# Creăm un socket și îl conectăm la server
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('sys.ase.ro',8924))

# Facem un loop pentru trimitere și primire de mesaje
while True:
    #Adăugam numele de utilizator și îl trimitem server-ului
    #După care așteptăm raspuns de la server pentru a confirma că este corespunzător
    mesaj = "Dragos"
    s.send(mesaj.encode('utf-8'))
    print("Așteptăm confirmarea username-ului...")
    raspuns = s.recv( 1024 ).decode( 'utf-8' )
    print("Răspuns: ", str(raspuns))
    
    #Adăugam parola utilizatorului și o trimitem server-ului
    #După care așteptăm raspuns de la server pentru a confirma că este corespunzător
    mesaj = "dragos"
    s.send(mesaj.encode('utf-8'))
    print("Așteptăm confirmarea parolei...")
    raspuns = s.recv( 1024 ).decode( 'utf-8' )
    print("Răspuns: ", str(raspuns))
    #La finally, inchidem socketul si iesim din structura alternativa
    s.close()
    break


