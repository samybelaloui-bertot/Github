----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:20:01 02/26/2016 
-- Design Name: 
-- Module Name:    display - Behavioral 
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

entity display is
    Port ( CE_1ms : in  STD_LOGIC;
           CE_1s : in  STD_LOGIC;
           data_R0 : in  STD_LOGIC_VECTOR (3 downto 0);
           data_R1 : in  STD_LOGIC_VECTOR (3 downto 0);
           data_L0 : in  STD_LOGIC_VECTOR (3 downto 0);
           data_L1 : in  STD_LOGIC_VECTOR (3 downto 0);
			  clk : in STD_LOGIC;
           AN : out  STD_LOGIC_VECTOR (3 downto 0);
           LEDS : out  STD_LOGIC_VECTOR (7 downto 0));
end display;

architecture Behavioral of display is

--COMPOSANTS

COMPONENT transcoder_2v4 
    Port ( A : in  STD_LOGIC_VECTOR (1 downto 0);
           O : out  STD_LOGIC_VECTOR (3 downto 0));
END COMPONENT transcoder_2v4;

COMPONENT mux_4x1x1b 
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           C : in  STD_LOGIC;
           D : in  STD_LOGIC;
           sel : in  STD_LOGIC_VECTOR (1 downto 0);
           O : out  STD_LOGIC);
END COMPONENT mux_4x1x1b;


COMPONENT mux_4x1x4b 
    Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
           B : in  STD_LOGIC_VECTOR (3 downto 0);
           C : in  STD_LOGIC_VECTOR (3 downto 0);
           D : in  STD_LOGIC_VECTOR (3 downto 0);
           sel : in  STD_LOGIC_VECTOR (1 downto 0);
           O : out  STD_LOGIC_VECTOR (3 downto 0));
END COMPONENT mux_4x1x4b;

COMPONENT transcoder_7segs 
    Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
           O : out  STD_LOGIC_VECTOR (6 downto 0));
END COMPONENT transcoder_7segs;

COMPONENT register_4b 
    Port ( D : in  STD_LOGIC_VECTOR (3 downto 0);
           CLK : in  STD_LOGIC;
           Q : out  STD_LOGIC_VECTOR (3 downto 0));
END COMPONENT register_4b;


COMPONENT register_8b 
    Port ( D : in  STD_LOGIC_VECTOR (7 downto 0);
           CLK : in  STD_LOGIC;
           Q : out  STD_LOGIC_VECTOR (7 downto 0));
END COMPONENT register_8b;


COMPONENT Tregister_1b 
    Port ( T : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           Q : out  STD_LOGIC);
END COMPONENT Tregister_1b;

COMPONENT counter_2b_E
    Port ( CE : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           Q : out  STD_LOGIC_VECTOR (1 downto 0));
END COMPONENT counter_2b_E;

--SIGNAUX INTERNES
signal AN_sel : STD_LOGIC_VECTOR (1 DOWNTO 0);
signal AN_T2v4 : STD_LOGIC_VECTOR (3 DOWNTO 0);
signal T1s : STD_LOGIC;
signal segs_data : STD_LOGIC_VECTOR (3 DOWNTO 0);
signal DP : STD_LOGIC;
signal sseg_7 : STD_LOGIC_VECTOR (6 DOWNTO 0);
signal sseg : STD_LOGIC_VECTOR (7 DOWNTO 0);

begin

--CABLAGE

--Concaténations
sseg(7 downto 0) <= DP & sseg_7(6 downto 0);


--U0
U0_counter_2b_E : counter_2b_E
PORT MAP(CE => CE_1ms,
			CLK => CLK,
			Q => AN_sel);

--U1
U1_transcoder_2v4 : transcoder_2v4
PORT MAP (A => AN_sel,
          O => AN_T2v4);

--U2
U2_register_4b : register_4b
PORT MAP (D => AN_T2v4,
			CLK => CLK,
			Q => AN);
			
--U3
U3_Tregister_1b : Tregister_1b
PORT MAP (T => CE_1s,
			CLK => CLK,
			Q => T1s);
			
--U4
U4_mux_4x1x1b : mux_4x1x1b
PORT MAP (A => '1',
			B => '1',
			C => '1',
			D => '1',
			O => DP,
			sel => AN_sel); 
			
--U5
U5_mux_4x1x4b : mux_4x1x4b
PORT MAP (A => data_R0,
			B => data_R1,
			C => data_L0,
			D => data_L1,
			sel => AN_sel,
			O => segs_data);

--U6
U6_transcoder_7segs : transcoder_7segs
PORT MAP (A => segs_data,
			O => sseg_7);
			
--U7
U7_register_8b : register_8b
PORT MAP (D => sseg,
			CLK => CLK,
			Q => LEDS);



end Behavioral;

