# POOArduino_projectGTB
## Présentation
**POOArduino_projectGTB** est un projet de Gestion Technique de Bâtiment (GTB) développé en C++ pour l'écosystème Arduino. L'objectif principal de ce code est de surveiller et d'analyser l'environnement d'une pièce ou d'un bâtiment en collectant des données environnementales de manière automatisée. 

Ce projet se distingue par son approche en **Programmation Orientée Objet (POO)**. Au lieu d'avoir un script monolithique classique, le système est découpé en plusieurs classes modulaires et réutilisables. Le projet s'articule autour d'une classe centrale, `CArduino`, qui agit comme le chef d'orchestre. Elle utilise le principe de *composition* pour instancier et gérer différents capteurs spécialisés. 

Le code est conçu pour interagir avec trois types de données environnementales clés, en utilisant l'héritage depuis une classe mère commune `CCapteur` pour harmoniser leur comportement :
* **🌡️ Température et Humidité** (`CTemperatureHumidite`) : Pour surveiller le confort thermique.
* **☀️ Luminosité** (`CLuminosite`) : Pour optimiser l'éclairage naturel et artificiel.
* **💨 Qualité de l'air** (`CTauxCO2`) : Pour mesurer le taux de CO2 et assurer une bonne ventilation.

Cette structure rend le code extrêmement évolutif : si nous souhaitons ajouter un nouveau capteur à l'avenir, il suffira de créer une nouvelle classe héritant de `CCapteur` sans perturber le reste du programme.

## Diagramme de classe

``` Mermaid
classDiagram
    direction TB
    class CCapteur {
        - int _id
        - bool _isConnected
        - float _value[2]
        - int _pin
        - bool _pinMode
        + CCapteur(id: int, pin: int)
        + ~CCapteur()
        + getId() int
        + getIsConnected() bool
        + getValue() float
        + getPin() int
        + getPinMode() bool
        + initialiser() void
    }

    class CLuminosite {
        + CLuminosite(id: int, pin: int)
        + ~CLuminosite()
        + initialiser() void
        + lireLuminosite() float
    }

    class CTemperatureHumidite {
        - float _temperature
        - float _humidite
        + CTemperatureHumidite(id: int, pin: int)
        + ~CTemperatureHumidite()
        + initialiser() void
        + lireTemperature() float
        + lireHumidite() float
    }

    class CTauxCO2 {
        + CTauxCO2(id: int, pin: int)
        + ~CTauxCO2()
        + initialiser() void
        + lireTauxCO2() float
    }

    class CArduino {
        - CTemperatureHumidite* _tempHum
        - CLuminosite* _lum
        - CTauxCO2* _co2
        + CArduino()
        + ~CArduino()
        + setUp() void
        + loop() void
        + initialiser() void
        + envoyerDonnées() void
    }

    CCapteur <|-- CLuminosite
    CCapteur <|-- CTemperatureHumidite
    CCapteur <|-- CTauxCO2
    CArduino *-- CTemperatureHumidite
    CArduino *-- CLuminosite
    CArduino *-- CTauxCO2
```

## Organisation des fichiers

- **src/** : Contient les fichiers source (.ino, .cpp)
  - `POOArduino_projectGTB.ino` : Fichier principal du sketch Arduino
  - `CArduino.cpp` : Implémentation de la classe principale
  - `CCapteur.cpp` : Implémentation de la classe de base des capteurs
  - `CTemperatureHumidite.cpp` : Implémentation du capteur température/humidité
  - `CLuminosite.cpp` : Implémentation du capteur de luminosité
  - `CTauxCO2.cpp` : Implémentation du capteur de CO2

- **include/** : Contient les fichiers d'en-tête (.h)
  - `CArduino.h` : Déclaration de la classe principale
  - `CCapteur.h` : Déclaration de la classe de base des capteurs
  - `CTemperatureHumidite.h` : Déclaration du capteur température/humidité
  - `CLuminosite.h` : Déclaration du capteur de luminosité
  - `CTauxCO2.h` : Déclaration du capteur de CO2

- **lib/** : Pour les bibliothèques externes si nécessaire

- **README.md** : Documentation du projet

## Comment utiliser

1. Ouvrez le dossier `src/` dans l'IDE Arduino ou VS Code avec l'extension Arduino.
2. Le fichier `POOArduino_projectGTB.ino` est le point d'entrée.
3. Assurez-vous d'inclure les bibliothèques nécessaires (ex: DHT pour température/humidité).
4. Compilez et téléversez sur votre Arduino.

Cette structure permet une séparation claire entre les déclarations et les implémentations, facilitant la programmation orientée objet.
