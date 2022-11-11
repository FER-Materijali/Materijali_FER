
/* Written by Tom Shiple, 25 October 1995 */ 
/* Symbolic variables */ 
typedef enum {YES, NO} boolean; 
typedef enum {START, SHORT, LONG} timer_state; 
typedef enum {GREEN, YELLOW, RED} color; 

module main(clk); 
input clk; 

color wire farm_light, hwy_light; 
wire start_timer, short_timer, long_timer; 
boolean wire car_present; 
wire enable_farm, farm_start_timer, enable_hwy, hwy_start_timer; 

assign start_timer = farm_start_timer || hwy_start_timer; 

timer timer(clk, start_timer, short_timer, long_timer); 
sensor sensor(clk, car_present); 
farm_control farm_control(clk, car_present, enable_farm, short_timer, long_timer, 
                          farm_light, farm_start_timer, enable_hwy); 
hwy_control hwy_control (clk, car_present, enable_hwy, short_timer, long_timer, 
                         hwy_light, hwy_start_timer, enable_farm); 

endmodule 

module sensor(clk, car_present); 
input clk; 
output car_present; 

wire rand_choice; 
boolean reg car_present; 

initial car_present = NO; 
assign rand_choice = $ND(0,1); 

always @(posedge clk) begin 

if (rand_choice == 0) 
    car_present = NO; 
else 
    car_present = YES; 
end 
endmodule 

module timer(clk, start, short, long); 
input clk; 
input start; 
output short; 
output long; 

wire rand_choice; 
wire start, short, long; 
timer_state reg state; 

initial state = START; 
assign rand_choice = $ND(0,1); 

/* short could as well be assigned to be just (state == SHORT) */ 
assign short = ((state == SHORT) || (state == LONG)); 
assign long = (state == LONG); 

always @(posedge clk) begin 
    if (start) state = START; 
    else 
       begin 
         case (state) 
         START: 
               if (rand_choice == 1) state = SHORT; 
         SHORT: 
               if (rand_choice == 1) state = LONG; 
               /* if LONG, remains LONG until start signal received */ 
         endcase 
      end 
end 
endmodule 

module farm_control(clk, car_present, enable_farm, short_timer, long_timer, 
                    farm_light, farm_start_timer, enable_hwy); 
input clk; 
input car_present; 
input enable_farm; 
input short_timer; 
input long_timer; 

output farm_light; 
output farm_start_timer; 
output enable_hwy; 

boolean wire car_present; 
wire short_timer, long_timer; 
wire farm_start_timer; 
wire enable_hwy; 
wire enable_farm; 
color reg farm_light; 

initial farm_light = RED; 
assign farm_start_timer = (((farm_light == GREEN) && ((car_present == NO) || long_timer)) 
                           || (farm_light == RED) && enable_farm); 

assign enable_hwy = ((farm_light == YELLOW) && short_timer); 

always @(posedge clk) begin 
   case (farm_light) 
   GREEN: 
         if ((car_present == NO) || long_timer) farm_light = YELLOW; 
   YELLOW: 
         if (short_timer) farm_light = RED; 
   RED: 
         if (enable_farm) farm_light = GREEN; 
   endcase 
end 
endmodule 

module hwy_control(clk, car_present, enable_hwy, short_timer, long_timer, 
                   hwy_light, hwy_start_timer, enable_farm); 
input clk; 
input car_present; 
input enable_hwy; 
input short_timer; 
input long_timer; 
output hwy_light; 
output hwy_start_timer; 
output enable_farm; 

boolean wire car_present; 
wire short_timer, long_timer; 
wire hwy_start_timer; 
wire enable_farm; 
wire enable_hwy; 
color reg hwy_light; 

initial hwy_light = GREEN; 
assign hwy_start_timer = (((hwy_light == GREEN) && ((car_present == YES) && long_timer)) 
                          || (hwy_light == RED) && enable_hwy); 
assign enable_farm = ((hwy_light == YELLOW) && short_timer); 
always @(posedge clk) begin 
   case (hwy_light) 
     GREEN: 
           if ((car_present == YES) && long_timer) hwy_light = YELLOW; 
     YELLOW: 
           if (short_timer) hwy_light = RED; 
     RED: 
           if (enable_hwy) hwy_light = GREEN; 
   endcase 
end 
endmodule 
