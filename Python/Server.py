import socket

# Creăm un socket și îi dăm bind la host pe portul 
8924
HOST = 'sys.ase.ro'
PORT = 8924
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen(1) 
#Numarul de conexiuni la port

#  Facem loop pentru a recepționa și trimite mai multe mesaje cu clientul
while True:
    # Acceptăm conexiuni
    #Afișăm totodată adresa, portul și host-ul
    client, address = s.accept()
    print("Conectat de la adresa:", address)
    print("Pe portul: ",PORT)
    print("Și hostul: ",HOST)

    #Primim informațiile de la client și le decodăm
    data = client.recv( 1024 ).decode( 'utf-8' )
    print("Am primit :", repr(data))

    #Trimitem informații către client, codând cu UTF-8
    if (data == "Dragos"):
        raspuns = "Username corespunzător"
        client.send(raspuns.encode('utf-8'))
    else:
        raspuns = "Numele nu există în baza noastră de date"
        client.send(raspuns.encode('utf-8'))
    #Primim a doua informație și o decodăm cu UTF-8
    data = client.recv( 1024 ).decode( 'utf-8' )
    print("Primit :", repr(data))

    #Trimitem și al doilea răspuns
    if (data == "dragos"):
        raspuns = "Parolă corespunzătoare"
        client.send(raspuns.encode('utf-8'))
    else:
        raspuns = "Parola nu corespunde cu utilizatorul"
        client.send(raspuns.encode('utf-8'))
    #Închidem socket-ul
    s.close()
    break

