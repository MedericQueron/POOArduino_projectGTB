# POOArduino_projectGTB
## Présentation

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
        + lireCO2() float
    }

    class CArduino {
        - CTemperatureHumidite _Climat
        - CLuminosite _Lumiere
        - CTauxCO2 _CO2
        + CArduino()
        + ~CArduino()
        + setup() void
        + loop() void
        + envoyerDonnees() void
    }

    CCapteur <|-- CLuminosite
    CCapteur <|-- CTemperatureHumidite
    CCapteur <|-- CTauxCO2

    CLuminosite --* CArduino : 1
    CTemperatureHumidite --* CArduino : 1
    CTauxCO2 --* CArduino : 1

    
```