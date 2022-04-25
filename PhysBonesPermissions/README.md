# PhysBonesPermissions (Event 60)

# Copied documentation from [information-redacted](https://github.com/information-redacted)

Used to compute which actors can interact with which in an instance.

#### Client-raised
When raised by the client, this event contains an array of **full** user IDs that are allowed to interact with this user.

If self-interact is turned on, the array will also include the user themselves.
If interactions are paused, the array will be empty, except if self-interact is on, in which case, the array will only include the user themselves.


##### Examples:
The following are some examples of how this event would behave; The following assumptions are made:
  - Self is: `usr_00000000-0000-0000-0000-000000000000`
  - Friend is: `usr_00000000-0000-0000-0000-000000000001`
  - Someone else with default settings is: `usr_00000000-0000-0000-0000-000000000002`
  - Someone else with a **enable** override is: `usr_00000000-0000-0000-0000-000000000003`
  - Someone else with a **disable** override is: `usr_00000000-0000-0000-0000-000000000004`

**Everyone, self-interact on:**:
```json
[
	"usr_00000000-0000-0000-0000-000000000000", // Self
	"usr_00000000-0000-0000-0000-000000000001", // Friend
	"usr_00000000-0000-0000-0000-000000000002", // Someone else
	"usr_00000000-0000-0000-0000-000000000003"  // Someone else, overriden ON
]
```

**Everyone, self-interact off:**:
```json
[
	"usr_00000000-0000-0000-0000-000000000001", // Friend
	"usr_00000000-0000-0000-0000-000000000002", // Someone else
	"usr_00000000-0000-0000-0000-000000000003"  // Someone else, overriden ON
]
```

**Friends-only, self-interact on:**:
```json
[
	"usr_00000000-0000-0000-0000-000000000000", // Self
	"usr_00000000-0000-0000-0000-000000000001", // Friend
	"usr_00000000-0000-0000-0000-000000000003"  // Someone else, overriden ON
]
```

**Friends-only, self-interact off:**:
```json
[
	"usr_00000000-0000-0000-0000-000000000001", // Friend
	"usr_00000000-0000-0000-0000-000000000003"  // Someone else, overriden ON
]
```

**Nobody, self-interact on:**:
```json
[
	"usr_00000000-0000-0000-0000-000000000000", // Self
	"usr_00000000-0000-0000-0000-000000000003"  // Someone else, overriden ON
]
```

**Nobody, self-interact off:**:
```json
[
	"usr_00000000-0000-0000-0000-000000000003"  // Someone else, overriden ON
]
```

**Interactions paused, self-interact on:**:
```json
[
	"usr_00000000-0000-0000-0000-000000000000"  // Self
]
```

**Interactions paused, self-interact off:**:
```json
[]
```

---

#### Server-raised
The server responds to this event with an array of Int32 arrays (`Int32[][]`), the format of which is currently unknown.