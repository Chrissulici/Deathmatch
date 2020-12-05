##### DO THIS IF YOU HAVE HP GAUGE AND PERCENT HP ######
##### FIRST FOR HP GAUGE #####
##### SECOND FOR PERCENT HP #######


## SEARCH:

				self.hpGauge.Show()

## REPLACE:

				if app.ENABLE_DEATHMATCH_SYSTEM:
					if player.IsDeathMatchMap():
						self.hpGauge.Hide()
					else:
						self.hpGauge.Show()
						
						
## SEARCH:

				self.hpDecimal.Show()

## REPLACE:

				if app.ENABLE_DEATHMATCH_SYSTEM:
					if player.IsDeathMatchMap():
						self.hpDecimal.Hide()
					else:
						self.hpDecimal.Show()
						
