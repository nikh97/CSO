
#include <math.h>
#include "p3.h"

/*
 * Implementation file for functions
 * declared in p3.h
 */ 

const short BIAS = (1 << (NUM_OF_EXP_BITS -1 )) - 1; 

short get_E_from_bits( short bit_vector ) { 
    
    if(is_denormalized(bit_vector))
      return 1-BIAS;
    else
      return get_exp_from_bits(bit_vector) - BIAS;
    
}

short get_exp_from_bits ( short bit_vector ) { 
    
    short other = (bit_vector >> NUM_OF_FRAC_BITS);
    short sum = 0;

    int i;
    for(i = 0; i < NUM_OF_EXP_BITS; i++){

      sum += (((other >> i) & 0b1) << i);
    }

    return sum;

}
    
short is_normalized(short bit_vector ) {
    
    short other = (bit_vector >> NUM_OF_FRAC_BITS) & 0b111;

    if(other == 0b000)
    	return 0;
    else if(other == 0b111)
    	return 0;
    else
    	return 1;
     
}

short is_denormalized(short bit_vector ) {
    
   	short other = (bit_vector >> NUM_OF_FRAC_BITS) & 0b111;

   	if(other == 0b000)
   		return 1;
   	else
   		return 0;
}
        

float get_M_from_bits ( short bit_vector ) {
    
    float M;

    if(is_denormalized(bit_vector))
      M = 0.0;
    else
      M = 1.0;

    int i;
    for(i = 0; i < NUM_OF_FRAC_BITS; i++){

      M += ((bit_vector >> i) & 0b1)*(1.0/(1 << (NUM_OF_FRAC_BITS - i)));
    }

    return M;


}

short get_sign_from_bits (  short bit_vector ) { 
    
    short sign = (bit_vector & 0b00100000 ) >> 5;
    if (sign == 1) return -1;
    else return 1;  
    
}



float get_value_from_bits ( short bit_vector ) {
    
    
    if((bit_vector & 0b011100) == 0b011100){
      if((bit_vector & 0b000011) == 0){

        if(get_sign_from_bits(bit_vector) == -1)
          return -INFINITY;
        else
          return INFINITY;
      }else
        return NAN;
    }

    float E;
    if(get_E_from_bits(bit_vector) < 0){
      E = 1.0/(1 << (-1*get_E_from_bits(bit_vector)));
    } else{
      E = 1 << get_E_from_bits(bit_vector);
    }


    return get_sign_from_bits(bit_vector)*E*get_M_from_bits(bit_vector);
}
