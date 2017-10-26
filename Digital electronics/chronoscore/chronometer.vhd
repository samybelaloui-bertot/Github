----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:33:56 02/26/2016 
-- Design Name: 
-- Module Name:    chronometer - Behavioral 
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
use IEEE.STD_LOGIC_UNSIGNED.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity chronometer is
    Port ( START : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           WAIT_t : in  STD_LOGIC;
           CE_1s : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           sec_unit : out  STD_LOGIC_VECTOR (3 downto 0);
           sec_dec : out  STD_LOGIC_VECTOR (3 downto 0);
           min_unit : out  STD_LOGIC_VECTOR (3 downto 0);
           min_dec : out  STD_LOGIC_VECTOR (3 downto 0));
end chronometer;

architecture Behavioral of chronometer is

COMPONENT register_1b_R
Port ( D : in  STD_LOGIC;
           R : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           Q : out  STD_LOGIC);
END COMPONENT register_1b_R;

COMPONENT counterSen_4b_RE
Port ( CE : in  STD_LOGIC;
           R : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           Q : out  STD_LOGIC_VECTOR (3 downto 0);
           TC : out  STD_LOGIC);
END COMPONENT counterSen_4b_RE;

COMPONENT counterDec_4b_RE 
    Port ( CE : in  STD_LOGIC;
           R : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           Q : out  STD_LOGIC_VECTOR (3 downto 0);
           TC : out  STD_LOGIC);
END COMPONENT counterDec_4b_RE;


--SIGNAUX INTERNES
signal start_reg : STD_LOGIC;
signal or_out : STD_LOGIC;
signal CE_time45min : STD_LOGIC;
signal equ45 : STD_LOGIC;
signal CE_secDec : STD_LOGIC;
signal CE_minUni : STD_LOGIC;
signal CE_minDec : STD_LOGIC;
signal min_unit_int : STD_LOGIC_VECTOR (3 downto 0);
signal min_dec_int : STD_LOGIC_VECTOR (3 downto 0);


begin

--MODELISATION DU COMPOSANT OR 
--U0
U0_OR : or_out <= start_reg OR START;

--MODELISATION DU COMPOSANT EQU45min

min_unit <= min_unit_int;
min_dec <= min_dec_int;

U7_equ45min : equ45 <= '1' when (min_unit_int ="0101" and min_dec_int ="0100") else '0';


--MODELISATION DU COMPOSANT AND4N2
--U2
U2_AND4N2 : CE_time45min <= ((not WAIT_t) and start_reg and CE_1s and (not equ45));


--CABLAGE
--U1
U1_register_1b_R : register_1b_R
PORT MAP (D => or_out,
			R => RESET,
			clk => CLK,
			Q => start_reg);

--U3
U3_counterDec_4b_RE : counterDec_4b_RE
PORT MAP (CE => CE_time45min,
			R => RESET,
			clk => CLK,
			Q => sec_unit,
			TC => CE_secDec);

--U4
U4_counterSen_4b_RE : counterSen_4b_RE
PORT MAP (CE => CE_secDec,
			R => RESET,
			clk => CLK,
			Q => sec_dec,
			TC => CE_minUni);

--U5
U5_counterDec_4b_RE : counterDec_4b_RE
PORT MAP (CE => CE_minUni,
			R => RESET,
			clk => CLK,
			Q => min_unit_int,
			TC => CE_minDec);
			
--U6
U6_counterSen_4b_RE : counterSen_4b_RE
PORT MAP (CE => CE_minDec,
			R => RESET,
			clk => CLK,
			Q => min_dec_int,
			TC => open);
			
			

		
end Behavioral;

