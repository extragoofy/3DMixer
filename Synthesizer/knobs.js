class Knob {
    constructor(id, instrument){
        this.id = id;
        this.instrument = instrument;
    }
    
    get instrumentValue(){
        return this.instrument;
    }
}