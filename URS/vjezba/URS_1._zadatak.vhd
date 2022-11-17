----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    08:20:39 01/22/2008 
-- Design Name: 
-- Module Name:    zad1 - Behavioral 
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

entity zad1 is

Port ( sw : in  STD_LOGIC_VECTOR (3 downto 0);
      led : out  STD_LOGIC_VECTOR (3 downto 0)
		);	
		
end zad1;
 
architecture Behavioral of zad1 is

begin

led(0)<=sw(0) or sw(1);
led(1)<=sw(2) and sw(3);
led(2)<=(sw(0) or sw(1)) and (sw(2) and sw(3));
led(3) <= not sw(0) or (sw(1) and sw(3));

end Behavioral;

