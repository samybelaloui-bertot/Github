----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    19:14:13 02/26/2016 
-- Design Name: 
-- Module Name:    chronoscore - Behavioral 
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

entity chronoscore is
    Port ( GCLK : in  STD_LOGIC;
           START : in  STD_LOGIC;
           WAIT_t : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           BPOL : in  STD_LOGIC;
           BPV : in  STD_LOGIC;
           BPreset : in  STD_LOGIC;
           AN : out  STD_LOGIC_VECTOR (3 downto 0);
           LEDS : out  STD_LOGIC_VECTOR (7 downto 0));
end chronoscore;

architecture Behavioral of chronoscore is

--COMPOSANTS
--U0 
COMPONENT timeGenerator
	Port( GCLK : IN STD_LOGIC;
			CE_1ms : out STD_LOGIC;
			CE_1s : out STD_LOGIC;
			CLK : out STD_LOGIC );
END COMPONENT timeGenerator;

--U1
COMPONENT chronometer 
    Port ( START : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           WAIT_t : in  STD_LOGIC;
           CE_1s : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           sec_unit : out  STD_LOGIC_VECTOR (3 downto 0);
           sec_dec : out  STD_LOGIC_VECTOR (3 downto 0);
           min_unit : out  STD_LOGIC_VECTOR (3 downto 0);
           min_dec : out  STD_LOGIC_VECTOR (3 downto 0));
END COMPONENT chronometer;

--U2
COMPONENT score 
    Port ( BPOL : in  STD_LOGIC;
           CE_1ms : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           BPV : in  STD_LOGIC;
           BPreset : in  STD_LOGIC;
           OL_unit : out  STD_LOGIC_VECTOR (3 downto 0);
           OL_dec : out  STD_LOGIC_VECTOR (3 downto 0);
           vis_unit : out  STD_LOGIC_VECTOR (3 downto 0);
           vis_dec : out  STD_LOGIC_VECTOR (3 downto 0));
END COMPONENT score;

--U3
COMPONENT multiplexData 
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
END COMPONENT multiplexData;


--U4
COMPONENT display is
    Port ( CE_1ms : in  STD_LOGIC;
           CE_1s : in  STD_LOGIC;
           data_R0 : in  STD_LOGIC_VECTOR (3 downto 0);
           data_R1 : in  STD_LOGIC_VECTOR (3 downto 0);
           data_L0 : in  STD_LOGIC_VECTOR (3 downto 0);
           data_L1 : in  STD_LOGIC_VECTOR (3 downto 0);
			  CLK : in STD_LOGIC;
           AN : out  STD_LOGIC_VECTOR (3 downto 0);
           LEDS : out  STD_LOGIC_VECTOR (7 downto 0));
END COMPONENT display;


--SIGNAUX INTERNES
--Bit
signal CE_1ms_int : STD_LOGIC;
signal CE_1s_int : STD_LOGIC;
signal CLK_int : STD_LOGIC;

--Bus
signal SU : STD_LOGIC_VECTOR(3 DOWNTO 0);
signal SD : STD_LOGIC_VECTOR(3 DOWNTO 0);
signal MU : STD_LOGIC_VECTOR(3 DOWNTO 0);
signal MD : STD_LOGIC_VECTOR(3 DOWNTO 0);
signal VU : STD_LOGIC_VECTOR(3 DOWNTO 0);
signal VD : STD_LOGIC_VECTOR(3 DOWNTO 0);
signal OU : STD_LOGIC_VECTOR(3 DOWNTO 0);
signal OD : STD_LOGIC_VECTOR(3 DOWNTO 0);
signal DR0 : STD_LOGIC_VECTOR(3 DOWNTO 0);
signal DR1 : STD_LOGIC_VECTOR(3 DOWNTO 0);
signal DL0 : STD_LOGIC_VECTOR(3 DOWNTO 0);
signal DL1 : STD_LOGIC_VECTOR(3 DOWNTO 0);

begin

--U0 *****COMPOSANT A RAJOUTER DANS L'ARBORESCENCE QUAND IL SERA DISPO SUR ECAMPUS
U0_timeGenerator : timeGenerator
PORT MAP( GCLK => GCLK,
			CE_1ms => CE_1ms_int,
			CE_1s => CE_1s_int,
			CLK => CLK_int);
			

--U1
U1_chronometer : chronometer
PORT MAP( START => START,
			WAIT_t => WAIT_t,
			RESET => RESET,
			CE_1s => CE_1s_int,
			CLK => CLK_int,
			sec_unit => SU,
			sec_dec => SD,
			min_unit => MU,
			min_dec => MD);
			
--U2
U2_score : score
PORT MAP( BPOL => BPOL,
			BPV => BPV,
			BPreset => BPreset,
			CE_1ms => CE_1ms_int,
			CLK => CLK_int,
			vis_unit => VU,
			vis_dec => VD,
			OL_unit => OU,
			OL_dec => OD);

--U3
U3_multiplexData : multiplexData
PORT MAP( CE_1s => CE_1s_int,
			CLK => CLK_int,
			sec_unit => SU,
			sec_dec => SD,
			min_unit => MU,
			min_dec => MD,
			vis_unit => VU,
			vis_dec => VD,
			OL_unit => OU,
			OL_dec => OD,
			data_R0 => DR0,
			data_R1 => DR1,
			data_L0 => DL0,
			data_L1 => DL1);

--U4
U4_display : display
PORT MAP( CE_1ms => CE_1ms_int,
			CE_1s => CE_1s_int,
			CLK => CLK_int,
			data_R0 => DR0,
			data_R1 => DR1,
			data_L0 => DL0,
			data_L1 => DL1,
			AN => AN,
			LEDS => LEDS);




end Behavioral;

