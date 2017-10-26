--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   11:44:45 03/15/2016
-- Design Name:   
-- Module Name:   C:/CPE_users/TP_ELN2/Groupe D/BELALOUI-CHAVRET/Projet1/chronoscore/chronoscore_tb.vhd
-- Project Name:  chronoscore
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: chronoscore
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY chronoscore_tb IS
END chronoscore_tb;
 
ARCHITECTURE behavior OF chronoscore_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT chronoscore
    PORT(
         GCLK : IN  std_logic;
         START : IN  std_logic;
         WAIT_t : IN  std_logic;
         RESET : IN  std_logic;
         BPOL : IN  std_logic;
         BPV : IN  std_logic;
         BPreset : IN  std_logic;
         AN : OUT  std_logic_vector(3 downto 0);
         LEDS : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal GCLK : std_logic := '0';
   signal START : std_logic := '0';
   signal WAIT_t : std_logic := '0';
   signal RESET : std_logic := '0';
   signal BPOL : std_logic := '0';
   signal BPV : std_logic := '0';
   signal BPreset : std_logic := '0';

 	--Outputs
   signal AN : std_logic_vector(3 downto 0);
   signal LEDS : std_logic_vector(7 downto 0);

   -- Clock period definitions
   constant GCLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: chronoscore PORT MAP (
          GCLK => GCLK,
          START => START,
          WAIT_t => WAIT_t,
          RESET => RESET,
          BPOL => BPOL,
          BPV => BPV,
          BPreset => BPreset,
          AN => AN,
          LEDS => LEDS
        );

   -- Clock process definitions
   GCLK_process :process
   begin
		GCLK <= '0';
		wait for GCLK_period/2;
		GCLK <= '1';
		wait for GCLK_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for GCLK_period*10;

      -- insert stimulus here 

      wait;
   end process;

START <= '1' after 0 ns;
BPOL <='1' after 40 ns,
		'0' after 50 ns,
		'1' after 70 ns;
		
BPV <= '1' after 50 ns,
		'0' after 60 ns;
		


END;
