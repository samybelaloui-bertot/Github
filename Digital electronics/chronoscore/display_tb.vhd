--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   11:51:03 03/15/2016
-- Design Name:   
-- Module Name:   C:/CPE_users/TP_ELN2/Groupe D/BELALOUI-CHAVRET/Projet1/chronoscore/display_tb.vhd
-- Project Name:  chronoscore
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: display
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
 
ENTITY display_tb IS
END display_tb;
 
ARCHITECTURE behavior OF display_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT display
    PORT(
         CE_1ms : IN  std_logic;
         CE_1s : IN  std_logic;
         data_R0 : IN  std_logic_vector(3 downto 0);
         data_R1 : IN  std_logic_vector(3 downto 0);
         data_L0 : IN  std_logic_vector(3 downto 0);
         data_L1 : IN  std_logic_vector(3 downto 0);
         clk : IN  std_logic;
         AN : OUT  std_logic_vector(3 downto 0);
         LEDS : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal CE_1ms : std_logic := '0';
   signal CE_1s : std_logic := '0';
   signal data_R0 : std_logic_vector(3 downto 0) := (others => '0');
   signal data_R1 : std_logic_vector(3 downto 0) := (others => '0');
   signal data_L0 : std_logic_vector(3 downto 0) := (others => '0');
   signal data_L1 : std_logic_vector(3 downto 0) := (others => '0');
   signal clk : std_logic := '0';

 	--Outputs
   signal AN : std_logic_vector(3 downto 0);
   signal LEDS : std_logic_vector(7 downto 0);

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: display PORT MAP (
          CE_1ms => CE_1ms,
          CE_1s => CE_1s,
          data_R0 => data_R0,
          data_R1 => data_R1,
          data_L0 => data_L0,
          data_L1 => data_L1,
          clk => clk,
          AN => AN,
          LEDS => LEDS
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for clk_period*10;

      -- insert stimulus here 

      wait;
   end process;
	
	
	

END;
