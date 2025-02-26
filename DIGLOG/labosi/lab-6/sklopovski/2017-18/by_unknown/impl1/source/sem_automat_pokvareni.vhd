library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity sem_automat is
    port(
	clk, vanjski_reset: in std_logic;
	aR, aY, aG, pR, pG: out std_logic
    );
end sem_automat;

architecture mix_moore_mealy of sem_automat is

    -- kodne rijeci internog stanja automata
    constant s0: std_logic_vector := "000";
    constant s1: std_logic_vector := "001";
    constant s2: std_logic_vector := "010";
    constant s3: std_logic_vector := "011";
    constant s4: std_logic_vector := "100";
    constant s5: std_logic_vector := "101";
    constant s6: std_logic_vector := "110";
    constant s7: std_logic_vector := "111";

    -- ROM pregledna tablica za Mooreove izlaze
    type sem_rom_type is array(0 to 7) of std_logic_vector(4 downto 0);
    constant moore_rom: sem_rom_type := (
	--
	-- Bitovi	Funkcija
	---------------------------------------------------------------
	--     4	aR - crveno svjetlo za aute	
	--     3	aY - zuto svjetlo za aute	
	--     2	aG - zeleno svjetlo za aute	
	--     1	pR - crveno svjetlo za pjesake
	--     0	pG - zeleno svjetlo za pjesake
	--
	"01000", -- S0 -> samo �uto
	"00000", -- S1 -> ni�ta
	"01010", -- S2 -> zuto auto i crveno pjesaci
	"10010", -- S3 -> crveno auti i pjesaci
	"10001", -- S4 -> crveno auti i zeleno pjesaci
	"10010", -- S5 -> crveno auti i pjesaci
	"11010", -- S6 -> crveno i zuto za auto i crveno za pjesake
	"00110", -- S7 -> zeleno auto i crveno pjesaci
	others => "-----" 
    );

    -- interni signali za opis registara
    signal R_timer: std_logic_vector(3 downto 0);
    signal R_stanje: std_logic_vector(2 downto 0);

    -- ostali interni signali: 
    signal mijenjaj_stanje: std_logic;
    signal novo_stanje: std_logic_vector(2 downto 0);
    signal moore_rom_out: std_logic_vector(4 downto 0);

begin
    --
    -- Brojilo impulsa takta, signal "mijenjaj_stanje" je sinkroni reset.
    -- Brojilo ne smatramo integralnim dijelom automata za upravljanje
    -- semaforom, nego vanjskim modulom ciji se izlazi dovode na ulaze
    -- automata.
    --
    process(clk, mijenjaj_stanje)
    begin
	if rising_edge(clk) then
	    if mijenjaj_stanje = '1' then
		R_timer <= x"0";
	    else
		R_timer <= R_timer + 1;
	    end if;
	end if;
    end process;


    --
    -- AUTOMAT ZA UPRAVLJANJE SEMAFOROM
    -- ================================
    --

    --
    -- Kombinacijski sklop koji odredjuje moguce slijedece stanje.
    --
    novo_stanje <=
      s0 when vanjski_reset = '1' and R_stanje /= s0 else
      s2 when R_stanje = s7 else
      R_stanje + 1;

    --
    -- Registar stanja, signal "mijenjaj_stanje" je write enable ulaz.
    --
    process(clk, mijenjaj_stanje)
    begin
	if rising_edge(clk) and mijenjaj_stanje = '1' then
	    R_stanje <= novo_stanje;
	end if;
    end process;

    --
    -- Mealyjev izlaz: ovisi i o trenutnom stanju "R_stanje" i o
    -- ulazima "vanjski_reset" i "R_timer".
    --
    mijenjaj_stanje <= '1' when
      vanjski_reset = '1' or
      R_stanje = s0 or
      R_stanje = s1 or
      (R_stanje = s2 and R_timer = x"4") or
      (R_stanje = s3 and R_timer = x"3") or
      (R_stanje = s4 and R_timer = x"3") or
      (R_stanje = s5 and R_timer = x"4") or
      (R_stanje = s6 and R_timer = x"3") or
      (R_stanje = s7 and R_timer = x"D") 
      else '0';

    --
    -- Mooreovi izlazi: ovise samo o trenutnom stanju "R_stanje".
    --
    moore_rom_out <= moore_rom(conv_integer(R_stanje));
    aR <= moore_rom_out(4);	-- crveno svjetlo za aute
    aY <= moore_rom_out(3);	-- zuto svjetlo za aute
    aG <= moore_rom_out(2);	-- zeleno svjetlo za aute
    pR <= moore_rom_out(1);	-- crveno svjetlo za pjesake
    pG <= moore_rom_out(0);	-- zeleno svjetlo za pjesake

end mix_moore_mealy;
