# bbal_analytics

The way the data is sorted:
- Game contains many Events (stored in a vector)
- Event has many attributes including two Person's
- Person has an id

What needs to be done:
- Sorting the Events
  - The way each event is sorted is defined on page 2 of the prompt
- Parsing the event codes file
- Looking up the event codes in every Event object once the event codes file is parsed
- Finding a way to calculate plus/minus for every player based on the change of events
