----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:38:51 02/26/2016 
-- Design Name: 
-- Module Name:    register_1b_R - Behavioral 
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

entity register_1b_R is
    Port ( D : in  STD_LOGIC;
           R : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           Q : out  STD_LOGIC);
end register_1b_R;

architecture Behavioral of register_1b_R is


--Signaux internes
signal Q_int : STD_LOGIC:='0';

begin
	PROCESS(clk)
		BEGIN
			IF(rising_edge(clk)) THEN
				IF(R='1') THEN
					Q_int <= '0';
				
				ELSIF(R='0') THEN
					Q_int <= D;
				END IF;
				
			END IF;
	
	END PROCESS;
Q <= Q_int;


end Behavioral;

