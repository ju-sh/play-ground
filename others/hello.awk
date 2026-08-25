# Use with gawk

function timeliner(line) {
  split(line, hms, ":")
  h = hms[1]
  m = hms[2]
  split(hms[3], sms, ",")
  s = sms[1]
  ms = sms[2]/10
  rv = sprintf("%d:%02d:%02d.%02d",h,m,s,ms)
  return rv
}

function flush(IDX, start, end, TEXT) {
  initial = "Dialogue: Marked=0"
  middle = "DefaultVCD, NTP,0000,0000,0000,,{\pos(400,570)}"
  sstart = timeliner(start)
  send = timeliner(end)
  printf("%s,%s,%s,%s,%s\n", initial, sstart, send, middle, TEXT)
}

BEGIN{
  # Rows separated by blank lines
  #RS = "";

  # Columns separated by new lines
  #F = "\n"

  IDX = 0
  TIME = 0
  TEXT = ""
}

  # Change if ending is CRLF
  sub(/\r$/,"") {}

  # gawk has 3 arg match, but not awk
  match($0, /^([0-9]+$)/, a) {
    if (IDX==0 && TIME==0) {
      IDX=a[1]
      next
    }
  }

  match($0, /([0-9]{2}:[0-9]{2}:[0-9]{2},[0-9]{3}) --> ([0-9]{2}:[0-9]{2}:[0-9]{2},[0-9]{3})/, a) {
    if (IDX!=0 && TIME==0) {
      start = a[1]
      end = a[2]

      # Set flag
      TIME = 1

      TEXT = "" 
      next
    }
  }

  # Anything other than a blank line
  !/^\s*$/ {
    TEXT = TEXT$0
  }

  match($0, /^$/, a) {
    if (IDX!=0 && TIME!=0) {
      flush(IDX, start, end, TEXT)

      # Reset flags
      TIME = 0
      IDX = 0
    }
  }

  END {
    flush(IDX, start, end, TEXT)
  }
