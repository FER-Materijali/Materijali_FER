typedef enum {A, B, C, X} selection;
typedef enum {IDLE, READY, BUSY} controller_state;
typedef enum {NO_REQ, REQ, HAVE_TOKEN} client_state;

module main(clk);
input clk;
output ackA, ackB, ackC;

selection wire sel;
wire active;

assign active = pass_tokenA || pass_tokenB || pass_tokenC;

controller controllerA(clk, reqA, ackA, sel, pass_tokenA, A);
controller controllerB(clk, reqB, ackB, sel, pass_tokenB, B);
controller controllerC(clk, reqC, ackC, sel, pass_tokenC, C);
arbiter arbiter(clk, sel, active);

client clientA(clk, reqA, ackA);
client clientB(clk, reqB, ackB);
client clientC(clk, reqC, ackC);

endmodule

module controller(clk, req, ack, sel, pass_token, id);
input clk, req, sel, id;
output ack, pass_token;

selection wire sel, id;
reg ack, pass_token;
controller_state reg state;

initial state = IDLE;
initial ack = 0;
initial pass_token = 1;

wire is_selected;
assign is_selected = (sel == id);

always @(posedge clk) begin
  case(state)
    IDLE:
      if (is_selected)
        if (req)
          begin
          state = READY;
          end
        else
          pass_token = 1;
      else
        pass_token = 0;
    READY:
      begin
      state = BUSY;
      ack = 1;
      end
    BUSY:
      if (!req)
        begin
        state = IDLE;
        ack = 0;
        pass_token = 1;
        end
  endcase
end
endmodule

module arbiter(clk, sel, active);
input clk, active;
output sel;

selection wire sel;
selection reg state;

initial state = A;

assign sel = active ? state: X;

always @(posedge clk) begin
  case(state) 
    A:
      state = B;
    B:
      state = C;
    C:
      state = A;
  endcase
end
endmodule

module client(clk, req, ack);
input clk, ack;
output req;

reg req;
client_state reg state;

wire rand_choice;

initial req = 0;
initial state = NO_REQ;

assign rand_choice = $ND(0,1);

always @(posedge clk) begin
  case(state)
    NO_REQ:
      if (rand_choice)
        begin
        req = 1;
        state = REQ;
        end
    REQ:
      if (ack)
        state = HAVE_TOKEN;
    HAVE_TOKEN:
      if (rand_choice)
        begin
        req = 0;
        state = NO_REQ;
        end  
  endcase
end
endmodule
