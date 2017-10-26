----------------------------------------------------------------------------------
-- 
-- Engineer:       Renaud DAVIOT
-- 
-- Create Date:    2016 
--
-- Module Name:    DLL - Behavioral 
-- Project Name:   Chronoscore_VGA
--
-- Target Devices: XC3S200 (Spartan 3 - 200K)
-- 
-- Description: 
--
--
-- Revision 0.01 - File Created
--
----------------------------------------------------------------------------------

--------------------------------------
-- ~~~~~~~~ Librairies ~~~~~~~~~~~~ --
--------------------------------------

library ieee;                                     -- IEEE Library used
	use ieee.std_logic_1164.all;                  -- Generic package for std_logic data type

--  Uncomment the following lines to use the declarations that are
--  provided for instantiating Xilinx primitive components (buffer, etc...).
library UNISIM;
     use UNISIM.VComponents.all;
     
-----------------------------------------
-- ~~~~~~~~ External View ~~~~~~~~~~~~ --
-----------------------------------------

entity DLL is
    -- I/O ports --
    port( GCLK   : in std_logic;           -- Clock signal provided by quartz oscillator.
          CLK    : out std_logic           -- Global system clock. Positive-edge triggered.
    );

begin -- Joint description to all architectures  
    
end entity DLL;

------------------------------------------- 
-- ~~~~~~~~ Internal View 1 ~~~~~~~~~~~~ --
-------------------------------------------

architecture Behavioral of DLL is

-- ++++ Component Declarations ++++
-- ++++ Local Type Declarations ++++
-- ++++ Constant Declarations ++++
-- ++++ Signal Declarations ++++

      signal GCLK_int         : std_logic;
      signal GCLK_DLLOut      : std_logic;
      signal GCLK_clean_FB    : std_logic;

-- ++++ Procedure/Function Declarations ++++

begin

  -- IBUFG: Global Clock Buffer (sourced by an external pin)
   --        Spartan-3
   -- Xilinx HDL Language Template, version 13.4
    IBUFG_inst : IBUFG
        generic map (
            IOSTANDARD => "DEFAULT")
        port map (
            I => GCLK,    -- Clock buffer input (connect directly to top-level port)
            O => GCLK_int -- Clock buffer output
    );
   -- End of IBUFG_inst instantiation

   ---------------------------

   -- DCM: Digital Clock Manager Circuit
   -- Spartan-3
   -- Xilinx HDL Language Template, version 14.7

   DCM_inst : DCM
   
   generic map (
      CLKDV_DIVIDE          => 2.0,     --  Divide by: 1.5,2.0,2.5,3.0,3.5,4.0,4.5,5.0,5.5,6.0,6.5
                                        --             7.0,7.5,8.0,9.0,10.0,11.0,12.0,13.0,14.0,15.0 or 16.0
      CLKFX_DIVIDE          => 1,       --  Can be any interger from 1 to 32
      CLKFX_MULTIPLY        => 4,       --  Can be any integer from 1 to 32
      CLKIN_DIVIDE_BY_2     => FALSE,   --  TRUE/FALSE to enable CLKIN divide by two feature
      CLKIN_PERIOD          => 20.0,    --  Specify period of input clock
      CLKOUT_PHASE_SHIFT    => "NONE",  --  Specify phase shift of NONE, FIXED or VARIABLE
      CLK_FEEDBACK          => "1X",    --  Specify clock feedback of NONE, 1X or 2X
      DESKEW_ADJUST         => "SYSTEM_SYNCHRONOUS", --  SOURCE_SYNCHRONOUS, SYSTEM_SYNCHRONOUS or
                                        --     an integer from 0 to 15
      DFS_FREQUENCY_MODE    => "LOW",   --  HIGH or LOW frequency mode for frequency synthesis
      DLL_FREQUENCY_MODE    => "LOW",   --  HIGH or LOW frequency mode for DLL
      DUTY_CYCLE_CORRECTION => TRUE,    --  Duty cycle correction, TRUE or FALSE
      FACTORY_JF            => X"C080", --  FACTORY JF Values
      PHASE_SHIFT           => 0,       --  Amount of fixed phase shift from -255 to 255
      SIM_MODE              => "SAFE",  --  Simulation: "SAFE" vs "FAST", see "Synthesis and Simulation
                                        --  Design Guide" for details
      STARTUP_WAIT          => FALSE)   --  Delay configuration DONE until DCM LOCK, TRUE/FALSE
      
   port map (
      CLKIN     => GCLK_int,        -- Clock input (from IBUFG, BUFG or DCM)
      CLKFB     => GCLK_clean_FB,   -- DCM clock feedbackx
      ------------------
      CLK0      => GCLK_DLLOut,     -- 0 degree DCM CLK ouptput
      CLK90     => open,            -- 90 degree DCM CLK output
      CLK180    => open,            -- 180 degree DCM CLK output
      CLK270    => open,            -- 270 degree DCM CLK output
      CLKDV     => open,            -- Divided DCM CLK out (CLKDV_DIVIDE)
      CLK2X     => open,            -- 2X DCM CLK output
      CLK2X180  => open,            -- 2X, 180 degree DCM CLK out
      CLKFX     => open,            -- DCM CLK synthesis out (M/D)
      CLKFX180  => open,            -- 180 degree CLK synthesis out
      ------------------
      RST       => '0',             -- DCM asynchronous reset input
      PSCLK     => '0',             -- Dynamic phase adjust clock input
      PSINCDEC  => '0',             -- Dynamic phase adjust increment/decrement
      PSEN      => '0',             -- Dynamic phase adjust enable input
      ------------------
      LOCKED    => open,            -- DCM LOCK status output
      PSDONE    => open,            -- Dynamic phase adjust done output
      STATUS    => open             -- 8-bit DCM status bits output
   );
   -- End of DCM_inst instantiation

   ---------------------------

   -- BUFG: Global Clock Buffer (source by an internal signal)
   --       Spartan-3
   -- Xilinx HDL Language Template, version 13.4
   BUFG_inst : BUFG
   port map (   I => GCLK_DLLOut,    -- Clock buffer input
                O => GCLK_clean_FB   -- Clock buffer output
   );
    -- End of BUFG_inst instantiation

   ---------------------------
 
   CLK <=  GCLK_clean_FB;

end architecture;

------------------------------- 
-- ~~~~~~~~ END ~~~~~~~~~~~~ --
-------------------------------
