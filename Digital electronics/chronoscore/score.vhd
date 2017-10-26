----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    17:09:45 02/26/2016 
-- Design Name: 
-- Module Name:    score - Behavioral 
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

entity score is
    Port ( BPOL : in  STD_LOGIC;
           CE_1ms : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           BPV : in  STD_LOGIC;
           BPreset : in  STD_LOGIC;
           OL_unit : out  STD_LOGIC_VECTOR (3 downto 0);
           OL_dec : out  STD_LOGIC_VECTOR (3 downto 0);
           vis_unit : out  STD_LOGIC_VECTOR (3 downto 0);
           vis_dec : out  STD_LOGIC_VECTOR (3 downto 0));
end score;

architecture Behavioral of score is

COMPONENT register_1b_E 
    Port ( CE : in  STD_LOGIC;
           D : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           Q : out  STD_LOGIC);
END COMPONENT register_1b_E;

COMPONENT register_1b 
    Port ( D : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           Q : out  STD_LOGIC);
END COMPONENT register_1b;


COMPONENT counterDec_4b_RE 
    Port ( CE : in  STD_LOGIC;
           R : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           Q : out  STD_LOGIC_VECTOR (3 downto 0);
           TC : out  STD_LOGIC);
END COMPONENT counterDec_4b_RE;

--SIGNAUX INTERNES
signal bpol_r : STD_LOGIC;
signal bpol_d : STD_LOGIC; 
signal bpol_f : STD_LOGIC;
signal bpol_fr : STD_LOGIC;
signal bpol_inc : STD_LOGIC;
signal bpv_r : STD_LOGIC;
signal bpv_d : STD_LOGIC;
signal bpv_f : STD_LOGIC;
signal bpv_fr : STD_LOGIC;
signal bpv_inc : STD_LOGIC;
signal CE_OL : STD_LOGIC;
signal CE_VIS : STD_LOGIC;


begin
--MODELISATION DES COMPOSANTS XOR 
--U3
bpol_fr <= bpol_f XOR bpol_d;

--U8
bpv_fr <= bpv_f XOR bpv_d;

--MODELISATION DES COMPOSANTS NAND
--U4
bpol_inc <= bpol_fr AND bpol_d;

--U9
bpv_inc <= bpv_fr AND bpv_d;

--CABLAGE

--U0
U0_register_1b_E : register_1b_E
PORT MAP(D => BPOL,
			CE => CE_1ms,
			clk => CLK,
			Q => bpol_r);

--U1
U1_register_1b_E : register_1b_E
PORT MAP(D => bpol_r,
			CE => CE_1ms,
			clk => CLK,
			Q => bpol_d);

--U2
U2_register_1b : register_1b
PORT MAP(D => bpol_d,
			clk => CLK,
			Q => bpol_f);

--U5
U5_register_1b_E : register_1b_E
PORT MAP(D => BPV,
			CE => CE_1ms,
			clk => CLK,
			Q => bpv_r);

--U6
U6_register_1b_E : register_1b_E
PORT MAP(D => bpv_r,
			CE => CE_1ms,
			clk => CLK,
			Q => bpv_d);

--U7
U7_register_1b : register_1b
PORT MAP(D => bpv_d,
			clk => CLK,
			Q => bpv_f);

--U10
U10_counterDec_4b_RE : counterDec_4b_RE
PORT MAP (CE => bpol_inc,
			R => BPreset,
			clk => CLK,
			Q => OL_unit,
			TC => CE_OL);

--U11
U11_counterDec_4b_RE : counterDec_4b_RE
PORT MAP (CE => CE_OL,
			R => BPreset,
			clk => CLK,
			Q => OL_dec,
			TC => open);
			
--U12
U12_counterDec_4b_RE : counterDec_4b_RE
PORT MAP (CE => bpv_inc,
			R => BPreset,
			clk => CLK,
			Q => vis_unit,
			TC => CE_VIS);
			
--U13
U13_counterDec_4b_RE : counterDec_4b_RE
PORT MAP (CE => CE_VIS,
			R => BPreset,
			clk => CLK,
			Q => vis_dec,
			TC => open);
			
end Behavioral;

