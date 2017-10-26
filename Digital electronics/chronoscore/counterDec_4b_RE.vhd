----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:42:04 02/26/2016 
-- Design Name: 
-- Module Name:    counterDec_4b_RE - Behavioral 
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

entity counterDec_4b_RE is
    Port ( CE : in  STD_LOGIC;
           R : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           Q : out  STD_LOGIC_VECTOR (3 downto 0);
           TC : out  STD_LOGIC);
end counterDec_4b_RE;

architecture Behavioral of counterDec_4b_RE is

--SIGNAUX INTERNES
signal Q_int: STD_LOGIC_VECTOR (3 downto 0):= "0000";
signal TC_int : STD_LOGIC :='0';

begin

process(clk, R, CE)
	begin
		IF (R='1') THEN
			Q_int <= "0000";
			TC_int <= '0';
		
		
		ELSIF (R='0' AND rising_edge(clk) AND CE='1')THEN
									
				IF (Q_int = "1001") THEN	--ON REMET A 0 LE COMPTEUR ET ON MET TC A 1 QUAND Q_INT = 1001
					Q_int <= "0000";
									
					
				ELSE
					Q_int <= Q_int + 1; 		--SINON ON INCREMENTE
				END IF;

		END IF;
		
			IF( Q_int ="1001" AND CE='1') THEN
				TC_int <= '1';
			ELSE
				TC_int <= '0';
			END IF;
				
		
	end process;
	

Q <= Q_int;
TC <= TC_int;


end Behavioral;

