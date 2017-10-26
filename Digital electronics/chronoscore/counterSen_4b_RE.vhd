----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:40:41 02/26/2016 
-- Design Name: 
-- Module Name:    counterSen_4b_RE - Behavioral 
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
use ieee.std_logic_unsigned.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity counterSen_4b_RE is
    Port ( CE : in  STD_LOGIC;
           R : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           Q : out  STD_LOGIC_VECTOR (3 downto 0);
           TC : out  STD_LOGIC);
end counterSen_4b_RE;

architecture Behavioral of counterSen_4b_RE is

--SIGNAUX INTERNES
signal Q_int: STD_LOGIC_VECTOR (3 downto 0):= "0000";
signal TC_int : STD_LOGIC :='0';

begin

process(clk, R, CE)
	begin
		IF (R='1') THEN			--SI RESET ALORS ON REMET A 0
			Q_int <= "0000";
			TC_int <= '0';
		
		
		ELSIF (R='0' AND rising_edge(clk) AND CE='1')THEN 		--SI PAS DE RESET + FRONT + COMPTEUR PRECEDENT A 9
		
				IF (Q_int = "0101") THEN	--ON REMET A 0 LE COMPTEUR ET ON MET TC A 1 
					Q_int <= "0000";		
					
				ELSE		--SINON
					Q_int <= Q_int + 1; 		--ON INCREMENTE
				END IF;
		END IF;
		
				
			IF( Q_int ="0101" AND  CE='1') THEN		--SI Q = 5 ET QUE CE=1 DONC LE COMPTEUR PRECEDENT =9 ALORS TC=1
				TC_int <= '1';
			ELSE
				TC_int <= '0';
			END IF;
				

		
		
	end process;
	
Q <= Q_int;
TC <= TC_int;


end Behavioral;



