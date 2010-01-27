###############################################################################
#
# PhoneLogic event handlers
#
###############################################################################

#
# This is the namespace in which all functions below will exist. The name
# must match the corresponding section "[PhoneLogic]" in the configuration
# file. The name may be changed but it must be changed in both places.
#
namespace eval PhoneLogic {

#
# Checking to see if this is the current logic core type
#
if {$logic_name != [namespace tail [namespace current]]} {
  return;
}


#
# This variable indicates if the phoneline is up or not
# 
variable phoneline_is_up 0;


#
# Executed when the SvxLink software is started
# 
proc startup {} {
  global logic_name;
  Logic::startup;
}
set func $logic_name;
append func "::checkPeriodicIdentify";
Logic::addTimerTickSubscriber $func;


#
# Executed when a specified module could not be found
#
proc no_such_module {module_id} {
  Logic::no_such_module $module_id;
}


#
# an "overloaded" playMsg
#
proc playMsg {msg} {
  ::playMsg "PhoneLogic" $msg;
}


#
# Executed when a manual identification is initiated with the * DTMF code
#
proc manual_identification {} {
  Logic::manual_identification;
}


#
# Executed when the squelch just have closed and the RGR_SOUND_DELAY timer has
# expired.
#
proc send_rgr_sound {} {
  Logic::send_rgr_sound;
}


#
# Executed when an empty macro command (i.e. D#) has been entered.
#
proc macro_empty {} {
  Logic::macro_empty;
}


#
# Executed when an entered macro command could not be found
#
proc macro_not_found {} {
  Logic::macro_not_found;
}


#
# Executed when a macro syntax error occurs (configuration error).
#
proc macro_syntax_error {} {
  Logic::macro_syntax_error;
}


#
# Executed when the specified module in a macro command is not found
# (configuration error).
#
proc macro_module_not_found {} {
  Logic::macro_module_not_found;
}


#
# Executed when the activation of the module specified in the macro command
# failed.
#
proc macro_module_activation_failed {} {
  Logic::macro_module_activation_failed;
}


#
# Executed when a macro command is executed that requires a module to
# be activated but another module is already active.
#
proc macro_another_active_module {} {
  Logic::macro_another_active_module;
}


#
# Executed when an unknown DTMF command is entered
#
proc unknown_command {cmd} {
  Logic::unknown_command $cmd;
}


#
# Executed when an entered DTMF command failed
#
proc command_failed {cmd} {
  Logic::command_failed $cmd;
}


#
# Executed when a link to another logic core is activated.
#
proc activating_link {name} {
  Logic::activating_link $name;
}


#
# Executed when a link to another logic core is deactivated
#
proc deactivating_link {name} {
  Logic::deactivating_link $name;
}


#
# Executed when trying to deactivate a link to another logic core but the
# link is not currently active.
#
proc link_not_active {name} {
  Logic::link_not_active $name;
}


#
# Executed when trying to activate a link to another logic core but the
# link is already active.
#
proc link_already_active {name} {
  Logic::link_already_active $name;
}


#
# Executed each time the transmitter is turned on or off
#
proc transmit {is_on} {
  Logic::transmit $is_on;
}


#
# Executed each time the squelch is opened or closed
#
proc squelch_open {rx_id is_open} {
  Logic::squelch_open $rx_id $is_open;
}


#
# Executed once every whole minute
#
proc every_minute {} {
  Logic::every_minute;
}


#
# Executed when the phoneline is activated
#   reason  - The reason why the repeater was activated
#	      SQL_CLOSE	      - Open on squelch, close flank
#	      SQL_OPEN	      - Open on squelch, open flank
#	      CTCSS_CLOSE     - Open on CTCSS, squelch close flank
#	      CTCSS_OPEN      - Open on CTCSS, squelch open flank
#	      TONE	      - Open on tone burst (always on squelch close)
#	      DTMF	      - Open on DTMF digit (always on squelch close)
#	      MODULE	      - Open on module activation
#	      AUDIO	      - Open on incoming audio (module or logic linking)
#	      SQL_RPT_REOPEN  - Reopen on squelch after repeater down
#
proc phoneline_up {reason} {
  global mycall;
  global active_module;
  variable phoneline_is_up;
  
  set phoneline_is_up 1;
  playMsg "welcome_to";
  playSilence 100;
  spellWord $mycall;
  playMsg "repeater";
  playSilence 250;
  
  if {($reason != "SQL_OPEN") && ($reason != "CTCSS_OPEN") &&
      ($reason != "SQL_RPT_REOPEN")} {
    set now [clock seconds];
    if {$now-$Logic::prev_ident < $Logic::min_time_between_ident} {
      return;
    }
    set Logic::prev_ident $now;

    if {$active_module != ""} {
      playMsg "active_module";
      playMsg $active_module "name";
    }
  }
}


#
# Executed when the phoneline is deactivated
#   reason  - The reason why the repeater was deactivated
#             IDLE         - The idle timeout occured
#             SQL_FLAP_SUP - Closed due to interference
#
proc phoneline_down {reason} {
  global mycall;
  variable phoneline_is_up;

  set phoneline_is_up 0;
  
  if {$reason == "SQL_FLAP_SUP"} {
    playSilence 500;
    playMsg "interference";
    playSilence 500;
    return;
  }

  set now [clock seconds];
  if {$now-$Logic::prev_ident < $Logic::min_time_between_ident} {
    playTone 400 900 50
    playSilence 100
    playTone 360 900 50
    playSilence 500
    return;
  }
  set Logic::prev_ident $now;
    
  spellWord $mycall;
  playMsg "repeater";
  playSilence 250;
  
  #playMsg "../extra-sounds" "shutdown";
}


#
# Executed when there has been no activity on the repeater for
# IDLE_SOUND_INTERVAL milliseconds. This function will be called each
# IDLE_SOUND_INTERVAL millisecond until there is activity or the repeater
# is deactivated.
#
proc phoneline_idle {} {
  set iterations 8;
  set base 2;
  set max [expr {pow($base, $iterations)}];
  for {set i $iterations} {$i>0} {set i [expr $i - 1]} {
    playTone 1100 [expr {round(pow($base, $i) * 150 / $max)}] 100;
    playTone 1200 [expr {round(pow($base, $i) * 150 / $max)}] 100;
  }
}


#
# Executed once every whole minute to check if it's time to identify
#
proc checkPeriodicIdentify {} {
  variable phoneline_is_up;
  #if {!$phoneline_is_up} {
    Logic::checkPeriodicIdentify;
  #}
}


#
# Executed when a DTMF digit has been received
#   digit     - The detected DTMF digit
#   duration  - The duration, in milliseconds, of the digit
#
# Return 1 to hide the digit from further processing in SvxLink or
# return 0 to make SvxLink continue processing as normal.
#
proc dtmf_digit_received {digit duration} {
  return [Logic::dtmf_digit_received $digit $duration];
}


#
# Executed when a DTMF command has been received
#   cmd - The command
#
# Return 1 to hide the command from further processing is SvxLink or
# return 0 to make SvxLink continue processing as normal.
#
proc dtmf_cmd_received {cmd} {
  return [Logic::dtmf_cmd_received $cmd];
}


#
# Executed when the voice logger is being activated
#
proc activating_voice_logger {} {
  Logic::activating_voice_logger;
}


#
# Executed when the voice logger is being deactivated
#
proc deactivating_voice_logger {} {
  Logic::deactivating_voice_logger;
}


#
# Executed when trying to deactivate the voice logger even though it's
# not active
#
proc voice_logger_not_active {} {
  Logic::voice_logger_not_active;
}


#
# Executed when trying to activate the voice logger even though it's
# already active
#
proc voice_logger_already_active {} {
  Logic::voice_logger_already_active;
}


#
# Executed if the repeater opens but the squelch never opens again.
# This is probably someone who opens the repeater but do not identify.
#
proc identify_nag {} {
  playSilence 500;
  playMsg "please_identify";
  playSilence 500;
}


proc request_authentification {reason} {
  playTone 500 900 100;
  playSilence 50;
  playTone 400 900 100;
  playSilence 50;
  playTone 500 900 100;
  playMsg  "enter_pin";
}


proc wrong_pin {} {
  playTone 300 900 750;
  playMsg "wrong_pin";
}


proc auth_timeout {} {
  playTone 300 900 750;
}


proc phoneline_not_active {} {

}

proc access_granted {call} {
  playTone 400 900 100;
  playTone 500 900 100;
  playTone 600 900 100;
  playMsg "connecting_to_RF_gate";
  playSilence 500;
}


proc phone_disconnecting {} {
  playTone 600 900 100;
  playTone 500 900 100;
  playTone 400 900 100;
  playMsg "disconnecting_from_RF_gate";  
  playSilence 500;
}

proc incoming_phonecall {call} {
  Logic::inform_phone $call;
}

# end of namespace
}

#
# This file has not been truncated
#