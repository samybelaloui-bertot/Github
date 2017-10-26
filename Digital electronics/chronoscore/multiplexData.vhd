----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    16:11:56 02/26/2016 
-- Design Name: 
-- Module Name:    multiplexData - Behavioral 
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

entity multiplexData is
    Port ( CE_1s : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           sec_unit : in  STD_LOGIC_VECTOR (3 downto 0);
           vis_unit : in  STD_LOGIC_VECTOR (3 downto 0);
           sec_dec : in  STD_LOGIC_VECTOR (3 downto 0);
           vis_dec : in  STD_LOGIC_VECTOR (3 downto 0);
           OL_unit : in  STD_LOGIC_VECTOR (3 downto 0);
           min_unit : in  STD_LOGIC_VECTOR (3 downto 0);
           OL_dec : in  STD_LOGIC_VECTOR (3 downto 0);
           min_dec : in  STD_LOGIC_VECTOR (3 downto 0);
           data_R0 : out  STD_LOGIC_VECTOR (3 downto 0);
           data_R1 : out  STD_LOGIC_VECTOR (3 downto 0);
           data_L0 : out  STD_LOGIC_VECTOR (3 downto 0);
           data_L1 : out  STD_LOGIC_VECTOR (3 downto 0));
end multiplexData;

architecture Behavioral of multiplexData is

--COMPOSANTS
COMPONENT mux_2x1x4b 
    Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
           B : in  STD_LOGIC_VECTOR (3 downto 0);
           sel : in  STD_LOGIC;
           O : out  STD_LOGIC_VECTOR (3 downto 0));
END COMPONENT mux_2x1x4b;

COMPONENT freqgen_4b_E 
    Port ( CE : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           clk_5s : out  STD_LOGIC);
END COMPONENT freqgen_4b_E;

--SIGNAUX INTERNES
signal data_sel : STD_LOGIC;


begin
--CABLAGE
--U0
U0_freqgen_4b_E : freqgen_4b_E
PORT MAP(CE => CE_1s,
			clk => clk,
			clk_5s => data_sel);

--U1			
U1_mux_2x1x4b : mux_2x1x4b
PORT MAP(A => sec_unit,
			B => vis_unit,
			O => data_R0,
			sel => data_sel);
			
--U2			
U2_mux_2x1x4b : mux_2x1x4b
PORT MAP(A => sec_dec,
			B => vis_dec,
			O => data_R1,
			sel => data_sel);
			
--U3			
U3_mux_2x1x4b : mux_2x1x4b
PORT MAP(A => OL_unit,
			B => min_unit,
			O => data_L0,
			sel => data_sel);
			
--U4			
U4_mux_2x1x4b : mux_2x1x4b
PORT MAP(A => OL_dec,
			B => min_dec,
			O => data_L1,
			sel => data_sel);


end Behavioral;

