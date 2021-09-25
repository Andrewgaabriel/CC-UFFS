module mux4x1 (

    input [1:0] sel,
    input [15:0] dado1,
    input [15:0] dado2,
    input [15:0] dado3,
    input [15:0] dado4,

    output [15:0] saida
);

    assign saida = sel == 0 ?dado1 : sel == 1 ?dado2 : sel == 2 ?dado3 : dado4; 

    
endmodule