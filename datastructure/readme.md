### Modularidad :
    la modulariadad ayuda a manejar la complefijadad tanto del donimio como del proceso
    de desarrollo. Separar una aplicacion en modulos impacta directamente en la calidad del
    productor y en la economia tanto del desarrollo como la explotacion del producto.
    Mecanismo para coordinar trabajo de varios de desarrolladores, manejar interdependencias
    de las partes  y componer sistemas complejos de manera correcta robusta y economica.


   ### Descomposicion modular 
    Si el metodo permite descomponer un problema en un numero pequeño de subproblemas 
    menos complejos conectados por una estructura simple y lo suficientemente  indepen
    dientes de menera tal que la soluion a cada un de ellos puede obtenerse separadamente.

 ### COMPOSCION MODULAR
    un metodo satisface este criterio si favoroce la produccion de entidades de software que puedan ser libremente combinadas con 
    otras para producir nueas entidades.

### ENTENDIBILIDAD MODULAR 
    un metedo favorece este criterio si ayuda a producir modulos que pueden ser entendidos separadamente or lectores humanos, en el peor caso el lector deberia observar solo algunos pcoos modulos cercanos

### continuidad modular
    un metodo satisface el criterio de continuidad modular si un cmabio en la especificacion del problema resulta en un cmabio en uno solo o en unos pocos modulos del sistema, obtenido de la especificacion a traves del metodo. "extensibilidad"

 ### proteccion modular
    si lleva arquitecruas en las cuales el efecto de situaciones anormales ocurridas en tiempo de ejecucion en unmodul permanecen a este modulo, o al menos se propaga a unos pocos modulos.



pricipios :
### correspondencia directa
    entre la estructura del dominio y la estructura del modelo
    se deriva de continuidad  y descomposicion

### Pocas interfaces 
    cada modulo deberia comunicarse con la menor cantidad de modulos posibles
    se deriva de continuidad, proteccion, composicio

### interfaces pequeñas, bajo acoplamiento    
    si 2 mdulos deben comunicarse, deberian intercambiar la menor cnatidad de informacion posible.
    se deriva de continuidad, proteccion.

### interfaces EXplicitas
    Si dos modulos a y b se comunican, esto debe ser explicito en el texto de a o en el texto de b o en el de ambos.
    esta regla soporta: descomposicion, composicion. continuidad,entendibilidad.
