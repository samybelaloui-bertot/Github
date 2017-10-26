----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    08:30:58 02/16/2016 
-- Design Name: 
-- Module Name:    counter_2b_E - Behavioral 
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
use ieee.std_logic_unsigned.all; --Package pour le compteur

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity counter_2b_E is
    Port ( CE : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           Q : out  STD_LOGIC_VECTOR (1 downto 0));
end counter_2b_E;

architecture Behavioral of counter_2b_E is

signal Q_interne : STD_LOGIC_VECTOR (1 downto 0) :="00";

begin

PROCESS (clk)
	BEGIN
		IF (rising_edge(clk)) THEN
			IF (CE='1') THEN
				Q_interne <= Q_interne+1;
			END IF;
		END IF;
		
END PROCESS;

Q<=Q_interne;

end Behavioral;

