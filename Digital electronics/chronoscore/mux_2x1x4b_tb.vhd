--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   01:23:03 02/26/2016
-- Design Name:   
-- Module Name:   C:/Users/samyb/Documents/CPE/Electronique/Projet1/chronoscore/mux_2x1x4b_tb.vhd
-- Project Name:  chronoscore
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: mux_2x1x4b
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
 
ENTITY mux_2x1x4b_tb IS
END mux_2x1x4b_tb;
 
ARCHITECTURE behavior OF mux_2x1x4b_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT mux_2x1x4b
    PORT(
         A : IN  std_logic_vector(3 downto 0);
         B : IN  std_logic_vector(3 downto 0);
         sel : IN  std_logic;
         O : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic_vector(3 downto 0) := (others => '0');
   signal B : std_logic_vector(3 downto 0) := (others => '0');
   signal sel : std_logic := '0';

 	--Outputs
   signal O : std_logic_vector(3 downto 0);
  
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: mux_2x1x4b PORT MAP (
          A => A,
          B => B,
          sel => sel,
          O => O
        );

    sel <='0' after 0 ns,
	'1' after 20 ns,
	'0' after 40 ns,
	'1' after 60 ns;
	
	A <= "0100" after 0 ns;
	B <= "0010" after 20 ns;
	

END;
