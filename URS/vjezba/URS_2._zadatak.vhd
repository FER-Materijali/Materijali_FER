----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:07:55 01/18/2008 
-- Design Name: 
-- Module Name:    zad2 - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity zad2 is
    Port ( LED : out  STD_LOGIC_VECTOR (7 downto 0);
           CLK : in  STD_LOGIC;
           SW : in  STD_LOGIC_VECTOR (3 downto 0);
           BTN_EAST : in  STD_LOGIC;
           BTN_NORTH : in  STD_LOGIC;
           BTN_SOUTH : in  STD_LOGIC;
           BTN_WEST : in  STD_LOGIC;
           ROT_CENTER : in  STD_LOGIC);
end zad2;

architecture Behavioral of zad2 is

-----------------------------------------------------
type STATE_TYPE is (S1, S2, S3, S4); 
signal CurS : STATE_TYPE := S1; 
Signal NextS : STATE_TYPE := S1 ; 
-----------------------------------------------------

Signal ClkState : std_logic;
Signal ClkState1 : std_logic;

Signal Counter : std_logic_vector(15 downto 0) :="0000000000000000";
Signal Clk1 : std_logic;
Signal pomocni: std_logic_vector(2 downto 0);

begin

process(ClkState,CurS)

variable Operand1 : std_logic_vector(3 downto 0);
variable Operand2 : std_logic_vector(3 downto 0);
variable Rezultat : std_logic_vector(7 downto 0);
       
begin
	if(ClkState'event and ClkState='1') then
		case CurS is 		
			when S1 =>
				LED <= "11111111";
				NextS <= S2;
			when S2 =>
				LED (7 downto 4) <= "1000";
				LED (3 downto 0) <= SW (3 downto 0);
				Operand1(3 downto 0) := SW(3 downto 0);
				NextS <= S3;
			when S3 =>
				LED (7 downto 4) <= "0100";
				LED (3 downto 0) <= SW (3 downto 0);
				Operand2(3 downto 0) := SW(3 downto 0);
				NextS <= S4;
			when S4 =>
				if (pomocni(0) = '1') then
				    Rezultat:=Operand1-Operand2;
				elsif (pomocni(2) = '1') then
				    Rezultat:=Operand1*Operand2;
				elsif (pomocni(1)='1') then 
				    Rezultat:=Operand1+Operand2;
				end if;
				LED(7 downto 0) <= Rezultat(7 downto 0);
				NextS <= S1;		
		end case;
		
	end if;
end process;

process(ClkState)
begin
	if(BTN_EAST='1') then
		CurS <= S1;
	elsif(ClkState'event and ClkState='0') then
		CurS <= NextS;
	end if;
end process;

--------------------------------------------------
Clk1 <= Counter(15);
process(clk)
begin
	if(CLK'event and CLK='1') then
		Counter <= Counter +"0000000000000001";
	end if;
end process;
---------------------------------------------------
process(CLK1,ROT_CENTER)
begin
	if(ROT_CENTER = '1') then		
		ClkState1 <= '1';
		ClkState <= '1';
	elsif(CLK1'event and CLK1='1') then
		ClkState <= ClkState1;
		ClkState1 <= '0';
	end if;
end process;
----------------------------------------------------
process(BTN_WEST,BTN_SOUTH,BTN_NORTH)
begin 
	if(BTN_WEST ='1') then
		pomocni<="001";
	elsif(BTN_SOUTH='1') then
		pomocni<="010";
	elsif(BTN_NORTH='1') then
		pomocni<="100";
	end if;

end process;
end Behavioral;

