`include "operacao.v"

module testbench;


    reg reset = 0;
    reg clk = 0;
    reg inicio = 0;
    reg [7:0] X = 2;
    reg [15:0] A = 1;
    reg [15:0] B = 2;
    reg [15:0] C = 5;
    wire [15:0] resultado;
    wire pronto;
    wire comecou;

    //instanciamento do modulo operação
    operacao resolve(reset, clk, inicio, X, A, B, C, resultado, pronto, comecou);

    always #1 clk <= ~clk;

    initial begin
        $dumpvars;
        reset <= 1;

        #1;

        reset <= 0;
        inicio <= 1;

    #16
        $finish;
    end

    
endmodule