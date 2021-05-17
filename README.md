# pae
Plan de acción:

1. Crear una función en el arduino para encender y apagar el relé.
2. Conectar el arduino a la red wifi y verificar que es visible a otros dispositivos
3. Comunicación bidireccional de datos entre el arduino y otros dispositivos
   vía wifi (enviar string u otras variables de forma confiable)
4. interface del lado del cliente para programar o ejecutar acciones.

# setup con esp8266
usar arduino uno solo como programador, no como microcontrolador, el esp8266 es un microcontrolador en si, se puede usar aparte de otros microcontroladores y funciona mejor así

1. quitar el microcontrolador del arduino uno
2. conectar el esp8266 según el esquema
3. para programar el esp8266 conectar gpio0 a tierra, cuando se desea usar, se desconecta.
4. una vez programado el esp8266 conectar rst a tierra por unos segundos, desconectar rst de tierra y luego se puede usar el esp8266 normalmente

# instalar esp8266
arduino-cli core update-index
arduino-cli core install esp8266:esp8266
