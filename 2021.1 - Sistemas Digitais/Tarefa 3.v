module projetoFSM(
    input w,
    input clk,
    input reset,
    output C1,
    output H3,
    output Done,
    output H2,
    output C3,
    output H1,
    output C2
);

    reg y1;
    reg y0;
    reg state; //criei para controlar os estados A,B,C,D
    parameter A = 2'b00, B = 2'b01, C = 2'b10, D = 2'b11;

    assign C1 = y1 & y0;
    assign H3 = y1 & y0;
    assign Done = y1 & y0;

    assign H2 = ~y1 & y0;
    assign C3 = ~y1 & y0;

    assign H1 = y1 & ~y0;
    assign C2 = y1 & ~y0;




                 /* A: y1 <= 0, y0 <= 1, state <= B;
                    B: y1 <= 1, y0 <= 0, state <= C;
                    C: y1 <= 1, y0 <= 1, state <= D;
                    D: y1 <= 0, y0 <= 0, state <= A;
                 */
        /* equacao y1: */
        /* y1 <= (~y1 & y0) | (y1 & ~y0) */

        /* equacao y0: */
        /* y0 <= (y1 & ~y0) | (~y0 & w) */


    /* lógica para regs */

    always @(posedge clk or reset)
    begin

        if(reset == 1) y1 <= (~y1 & y0) | (y1 & ~y0), y0 <= (y1 & ~y0) | (~y0 & w), state <= A;
        else begin
            if(w==0) y1 <= (~y1 & y0) | (y1 & ~y0); y0 <= (y1 & ~y0) | (~y0 & w); state <= A; 
            else begin
                case(state)
                    A: y1 <= (~y1 & y0) | (y1 & ~y0), y0 <= (y1 & ~y0) | (~y0 & w), state <= B;
                    B: y1 <= (~y1 & y0) | (y1 & ~y0), y0 <= (y1 & ~y0) | (~y0 & w), state <= C;
                    C: y1 <= (~y1 & y0) | (y1 & ~y0), y0 <= (y1 & ~y0) | (~y0 & w), state <= D;
                    D: y1 <= (~y1 & y0) | (y1 & ~y0), y0 <= (y1 & ~y0) | (~y0 & w), state <= A;
                endcase
            end
        end
    end
endmodule;

/* ___________________________________________________________________ */

module testbench;


    reg w0 = 0;
    reg clk0 = 0;
    reg reset0 = 0;
    wire C10;
    wire H30;
    wire Done0;
    wire H20;
    wire C30;
    wire H10;
    wire C20;

    projetoFSM project(w0, clk0, reset0, C10, H30, Done0, H20, C30, H10, C20);

    always #1 begin /* cria um clock automatico q fica pulsando */
        clk0 <= ~clk0;
    end

    initial begin
        $dumpvars;
        //tempo
        reset0 <= 1;
        w0 <= 0;
        #1
        reset0 <= 0;
        #2
        w0 <= 1;
        #2
        w0 <= 0;
        #2
        w0 <= 1;
        #4
        w0 <= 0;
        #2
        w0 <= 1;
        #7
        w0 <= 0;

        $finish;
    end
    
endmodule


