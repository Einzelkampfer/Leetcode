# Write your MySQL query statement below
SELECT
	Scores.Score,
	rankTable.rank
FROM
	Scores,
	(
		SELECT
			sset.Score,
			@curRank := @curRank + 1 AS rank
		FROM
			(
				SELECT
					Scores.Score
				FROM
					Scores
				GROUP BY
					Scores.Score
			) AS sset,
			(SELECT @curRank := 0) r
		ORDER BY
			Score DESC
	) AS rankTable
WHERE
	Scores.Score = rankTable.Score
ORDER BY
	rank;