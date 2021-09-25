module blocoDeControle (
    input reset,
    input clk,
    input inicio,
    output [1:0] M0,
    output [1:0] M1,
    output [1:0] M2,
    output regLX,
    output regLS,
    output regLH,
    output H,
    output pronto,
    output comecou
);

reg[3:0] state;

    always @(posedge clk or reset) begin

        if (reset) // =1
            state <= 0; //reiniciaremos

        else begin
            if (state == 0 && ~inicio)
                state <= state;
            else begin
                if(state == 8)
                    state <= 0;
                else begin
                state <= state + 1; //incremento
                end
            end
        end
    end

//lógica implementação dos estados

//assign variavel1 = variavel2 == X1? X2 : X3 | x1,x2,x3 são numeros
//variavel1 q vai receber o valor
//se o valor da variavel2 for igual a X1, a variavel1 recebe X2, se não recebe X3 */
//modelo:
//assign variavel = state == 0? x : state == 1? x : state == 2? x : state == 3? x : state == 4? x : state == 5? x : state == 6? x : state == 7? x : 0; */

assign M0 = state == 3? 1 : state == 4? 2 : state == 5? 0 : state == 6? 3 : 0;

assign M1 = state == 1? 1 : state == 2? 1 : state == 3? 3 : state == 4? 0 : state == 5? 3 : state == 6? 0 : 0;

assign M2 = state == 1? 0 : state == 2? 0 : state == 3? 1 : state == 4? 0 : state == 5? 2 : state == 6? 2 : 0;

assign regLX = state == 1? 1 : 0;

assign regLS = state == 3? 1 : state == 4? 0 : state == 5? 1 : state == 6? 1 : 0;

assign regLH = state == 2? 1 : state == 3? 0 : state == 4? 1 : 0;

assign H = state == 1? 1 : state == 2? 1 : state == 3? 1 : state == 4? 1 : state == 5? 0 : state == 6? 0 : 0;

assign comecou = state == 0? 1 : state == 1? 0 : state == 2? 0 : state == 3? 0 : state == 4? 0 : state == 5? 0 : state == 6? 0 : state == 7? 0 : 0;

assign pronto = state == 0? 0 : state == 1? 0 : state == 2? 0 : state == 3? 0 : state == 4? 0 : state == 5? 0 : state == 6? 0 : state == 7? 1 : 0;



endmodule