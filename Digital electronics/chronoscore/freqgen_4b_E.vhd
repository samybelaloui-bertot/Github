----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    01:15:37 02/26/2016 
-- Design Name: 
-- Module Name:    freqgen_4b_E - Behavioral 
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
use ieee.std_logic_unsigned.all; --Package pour freqgen

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity freqgen_4b_E is
    Port ( CE : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           clk_5s : out  STD_LOGIC);
end freqgen_4b_E;

architecture Behavioral of freqgen_4b_E is
signal Qint : STD_LOGIC_VECTOR (3 downto 0) :="0000";
signal clk_5sint : STD_LOGIC := '0';

begin

PROCESS(clk)
	BEGIN
		 IF (rising_edge (clk)) THEN
			IF(CE='1') THEN
					Qint <= Qint+1;
					IF(Qint = "0100") THEN
						clk_5sint <= '1';
					END IF;
					
					IF(Qint = "1001") THEN
						clk_5sint <= '0';
						Qint <= "0000";
					
					END IF;
					
					
			END IF;
		END IF;
		
		

	END PROCESS;
clk_5s <= clk_5sint;


end Behavioral;

