----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    08:34:59 02/16/2016 
-- Design Name: 
-- Module Name:    Tregister_1b - Behavioral 
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Tregister_1b is
    Port ( T : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           Q : out  STD_LOGIC);
end Tregister_1b;

architecture Behavioral of Tregister_1b is

signal Q_interne : STD_LOGIC :='0';

begin

PROCESS (clk)
	BEGIN
		IF (rising_edge(clk)) THEN
			IF (T='1') THEN
				Q_interne <= NOT(Q_interne);
			END IF;
		END IF;
		
END PROCESS;

Q<=Q_interne;

end Behavioral;

